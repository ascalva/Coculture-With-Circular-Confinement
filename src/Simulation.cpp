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

#ifdef SEGREGATION
    //Populate randomly
    while( cellNum < this->totalCells ) {

        do {
            x = this->radius * this->randomGen->use(0x0000);
            y = this->radius * this->randomGen->use(0x0000);
        } while( sqrt(x*x + y*y) >= this->radius);

        //Randomly make x and/or y negative
        randomNegative(&x, &y);

        if( checkNeighbors(x, y) ) {
            if (cellNum < this->healthyCells) {
                this->population.push_back(new Cell(x, y, cellRad, 0, this->randomGen));
            } else {
                this->population.push_back(new Cell(x, y, cellRad, 1, this->randomGen));
            } cellNum++;
        }
    }
#else
    //Segregate population, one shielding the other
    double r1 = this->radius / sqrt(2.0);
//    while( cellNum < this->healthyCells ) {
    while( cellNum < this->healthyCells ) {
        do {
            x = this->radius * this->randomGen->use(0x0000);
            y = this->radius * this->randomGen->use(0x0000);
        } while( sqrt(x*x + y*y) >= r1 );

        randomNegative(&x, &y);
        if( checkNeighbors(x, y) ) {
            this->population.push_back(new Cell(x, y, cellRad, 0, this->randomGen));
            cellNum++;
        }
    } while( cellNum < this->totalCells) {
        do {
            x = this->radius * this->randomGen->use(0x0000);
            y = this->radius * this->randomGen->use(0x0000);
        } while( sqrt(x*x + y*y) <= r1 || sqrt(x*x + y*y) >= this->radius );

        randomNegative(&x, &y);
        if( checkNeighbors(x, y) ) {
            this->population.push_back(new Cell(x, y, cellRad, 1, this->randomGen));
            cellNum++;
        }
    }
#endif
    std::cout << "Population completed.." << endl;
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

void Simulation::randomNegative(double * x, double * y) {
    switch( rand() % 4 ) {
        case 1:
            *x *= -1;
            break;

        case 2:
            *y *= -1;
            break;

        case 3:
            *x *= -1;
            *y *= -1;
            break;

        default:
            break;
    }
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
    long print = 0;

    int HealthyDivides = 0;
    int UnhealthyDivides = 0;

    while(t < TMAX) {
        t += DT;

#ifndef NO_REPOPULATION

        /// Divide healthy cells
        int max = this->totalCells;
        int count = 0;
        if( !(print % (int) ((V0 * healthyReproduction)/actCellSize) )
            && HealthyDivides < maxHealthyDivides) {
            for( i = this->population.begin(); i != this->population.end(); ++i) {
                if( !(*i)->type() ) { //If type() returns 0 (healthy) negate val
                    this->population.push_back((*i)->divide());
                    this->healthyCells++;
                    this->totalCells++;
                }
                count++;
                if( count == max) break;
            } HealthyDivides++;
        }

        /// Divide unhealthy cells
        max = this->totalCells;
        count = 0;
        if( !(print % (int) ((V0 * unhealthyReproduction)/actCellSize))
                && UnhealthyDivides < maxUnhealthyDivides) {
            for( i = this->population.begin(); i != this->population.end(); ++i) {
                if( (*i)->type() ) { //If type() returns 1 (unhealthy)
                    this->population.push_back((*i)->divide());
                    this->unealthyCells++;
                    this->totalCells++;
                }
                count++;
                if( count == max) break;
            } UnhealthyDivides++;
        }
#endif
        for(i = this->population.begin(); i != this->population.end(); ++i) {
            for(j = this->population.begin(); j != this->population.end(); ++j) {
                (*i)->computeForce( *j );
            }
        }

        if( print == startMSD ) {
            for(i = this->population.begin(); i != this->population.end(); ++i) {
                (*i)->initMSD();
            }
        }
        double sqrtDispSumHealthy = 0;
        double sqrtDispSumCancer = 0;
        int curr = 0;
        for(i = this->population.begin(); i != this->population.end(); ++i) {
            (*i)->move( DT, this->radius );

            switch( (*i)->type() ) {
                case 0:
                    sqrtDispSumHealthy += (*i)->computeSquaredDisplacement();
                    break;
                default:
                    sqrtDispSumCancer += (*i)->computeSquaredDisplacement();
                    break;
            }

            if( !(print % TGAP) ) {
                cell = (*i)->getValues();
                data.precision(12);
                data << ++curr << " "
                     << std::get<0>(cell) << " "
                     << std::get<1>(cell) << " "
                     << std::get<2>(cell) << " "
                     << (*i)->type() << " "
                     << endl;
            }
        } if( !(print++ % TGAP) ) data << "\n\n";

        if( print > startMSD ) {
            sqrtDispSumHealthy /= this->healthyCells;
            sqrtDispSumCancer /= this->unealthyCells;
            meanSquaredDisplacement << t << " "
                                    << sqrtDispSumHealthy << " "
                                    << sqrtDispSumCancer << endl;
        }
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
