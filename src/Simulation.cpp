/**
 * filename: Simulation.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose:
 */

#include "../include/Simulation.h"


Simulation::Simulation(FILE * fp1)
        : fp1(fp1),
          radius(R)
{
    this->totalCells = (int) ((PHI * 4 * R * R) / M_PI);
    this->unealthyCells = (int) (this->totalCells / (1.0 + RATIO));
    this->healthyCells = (int) (this->unealthyCells * RATIO);

    this->randomGen = new class randomGen((long) SEED1, (long) SEED2);
}

void Simulation::populate() {

    double cellRad = FINAL_RADIUS;

    Cell * temp;
    double x, y;
    int cellNum = 0;

    while( cellNum < this->totalCells ) {

        do {
            x = this->radius * this->randomGen->use(0x0000);
            y = this->radius * this->randomGen->use(0x0000);
        } while( sqrt(x*x + y*y) >= this->radius);

        //Randomly make x and/or why negative
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
                temp = new Cell(x, y, cellRad, 0, this->randomGen);
                this->population.push_back(*temp);
            } else {
                temp = new Cell(x, y, cellRad, 1, this->randomGen);
                this->population.push_back(*temp);
            }
            cellNum++;
        }
    }
}

bool Simulation::checkNeighbors(double x, double y) {
    vector<Cell>::iterator it;
    for( it = this->population.begin(); it != this->population.end(); ++it ) {
        std::tuple<double, double, double> cell = it->getValues();
        double dx = x - std::get<0>(cell);
        double dy = y - std::get<1>(cell);
        /*opt*/
        dx = dx - (2.0 * this->radius * (int)(dx/(this->radius)));
        dy = dy - (2.0 * this->radius * (int)(dy/(this->radius)));

        double drsq = (dx * dx) + (dy * dy);

        if( drsq < 1.0) {///might be off
            return false;
        }
    } return true;
}

void Simulation::run() {
    vector<Cell>::iterator i;
    vector<Cell>::iterator j;
    std::tuple<double, double, double> cell;

    while(double t = 0.0 < TMAX) {
        t += DT;

        for(i = this->population.begin(); i != this->population.end(); ++i) {
            for(j = this->population.begin(); j != this->population.end(); ++j) {
                i->computeForce( *j );
            }
        }

        int curr = 0;
        for(i = this->population.begin(); i != this->population.end(); ++i) {
            i->move( DT, this->radius );
            cell = i->getValues();
#ifndef CMD_OUT
            fprintf(fp1, "%2d %e   %5e   %5e   %5d\n",
                    ++curr,
                    std::get<0>(cell),
                    std::get<1>(cell),
                    std::get<2>(cell),
                    i->type());
#else
            printf( "%4d %e %5e %5e %5d\n",
                    ++curr,
                    std::get<0>(cell),
                    std::get<1>(cell),
                    std::get<2>(cell),
                    i->type());
#endif
        }

#ifndef CMD_OUT
        fprintf(fp1, "\n\n");
#else
        printf("\n\n");
#endif

    }
}
