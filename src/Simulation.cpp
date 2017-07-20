/**
 * filename: Simulation.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose: Creates and stores all instances of the Cell class and extract all relevant information
 *          about their interaction and stores in different data files.
 */

#include "../include/Simulation.h"

Simulation::Simulation()
        : radius(confinementRadius)
{
    this->totalCells = (int) ((PHI * this->radius * this->radius) / (cellRadius * cellRadius));
    this->unealthyCells = (int) (this->totalCells / (1.0 + RATIO));
    this->healthyCells = (int) (this->unealthyCells * RATIO);

    this->randomGen = new class randomGen( SEED1, SEED2 );

}

void Simulation::populate() {

    double cellRad = cellRadius;
    double x, y;
    int cellNum = 0;
    std::cout << "Starting to populate.." << endl;

    while( cellNum < this->totalCells ) {

        do {
            x = this->radius * this->randomGen->use(0x0000);
            y = this->radius * this->randomGen->use(0x0000);
        } while( sqrt(x*x + y*y) >= this->radius);

        //Randomly make x and/or y negative
        switch( rand() % 4 ) {
            case 1:
                x *= -1;
                break;

            case 2:
                y *= -1;
                break;

            case 3:
                x *= -1;
                y *= -1;
                break;

            default:
                break;
        }

        if( checkNeighbors(x, y) ) {
            if (cellNum < this->healthyCells) {
                this->population.push_back(new Cell(x, y, cellRad, 0, this->randomGen));
            } else {
                this->population.push_back(new Cell(x, y, cellRad, 1, this->randomGen));
            } cellNum++;
        }
    } std::cout << "Population completed.." << endl;
}

bool Simulation::checkNeighbors(double x, double y) {
    vector<Cell*>::iterator it;
    for( it = this->population.begin(); it != this->population.end(); ++it ) {
        std::tuple<double, double, double> cell = (*it)->getValues();
        double dx = x - std::get<0>(cell);
        double dy = y - std::get<1>(cell);
        /*opt*/
        dx = dx - (2.0 * this->radius * (int)(dx/(this->radius)));
        dy = dy - (2.0 * this->radius * (int)(dy/(this->radius)));

        double drsq = (dx * dx) + (dy * dy);

        if( drsq < (INIT_MIN_SPACING * INIT_MIN_SPACING) ) {
            return false;
        }
    } return true;
}

void Simulation::run() {
    vector<Cell*>::iterator i;
    vector<Cell*>::iterator j;
    std::tuple<double, double, double> cell;

    std::cout << "Now starting simulation.." << endl;
    printMeta();
    ofstream data("./coculture.dat");
    ofstream meanSquaredDisplacement("./meanSqrtDisp.dat");

    double t = 0.0;
    int print = 0;

    while(t < TMAX) {
        t += DT;

        for(i = this->population.begin(); i != this->population.end(); ++i) {
            for(j = this->population.begin(); j != this->population.end(); ++j) {
                (*i)->computeForce( *j );
            }
        }

        int curr = 0;
        double sqrtDispSumHealthy = 0;
        double sqrtDispSumCancer = 0;
        for(i = this->population.begin(); i != this->population.end(); ++i) {
            (*i)->move( DT, this->radius );

            switch( (*i)->type() ) {
                case 0:
                    sqrtDispSumHealthy += (*i)->computeSquaredDisplacement();
                    break;
                default:
                    sqrtDispSumCancer += (*i)->computeSquaredDisplacement();
//                    sqrtDispSumHealthy += (*i)->computeSquaredDisplacement(); ///temp
                    break;
            }
            if( !(print%100) ) {
                cell = (*i)->getValues();
                data.precision(12);
                data << ++curr << " "
                     << std::get<0>(cell) << " "
                     << std::get<1>(cell) << " "
                     << std::get<2>(cell) << " "
                     << (*i)->type() << " "
                     << endl;
            }
        } if( !(print++%100) ) data << "\n\n";

        sqrtDispSumHealthy /= this->healthyCells;
        sqrtDispSumCancer /= this->unealthyCells;
//        sqrtDispSumHealthy /= this->totalCells; ///tmp
        meanSquaredDisplacement << t << " "
                                << sqrtDispSumHealthy << " "
                                << sqrtDispSumCancer << endl;
    }
    data.close();
    meanSquaredDisplacement.close();
}

void Simulation::printMeta() {

    ofstream meta("./meta.dat");
    meta << "Ratio\t" << "1:1" << "\n"
         << "CellNumber\t" << this->totalCells << "\n"
         << "PackingFraction\t" << PHI << "\n"
         << "ConfinementRadius\t" << this->radius << "\n"
         << "CellRadius\t" << cellRadius
         << endl;
    meta.close();
}
