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

    randomGen::instance()->setValues((long) SEED1, (long) SEED2);
}

void Simulation::grow() {
    vector<Cell>::iterator it;
    for(it = this->population.begin(); it != this->population.end(); ++it) {
        it->modGrowth( GROWTH_RATE );
    }
}

void Simulation::populate() {
    Cell * temp;
    double x, y;
    int cellNum;

    for( cellNum = 0; cellNum < this->totalCells; cellNum++ ) {
        x = this->radius * ran2(&seed);
        y = this->radius * ran2(&seed);

        //Randonly make x and/or why negative
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

        if( cellNum < this->healthyCells ) {
            temp = new Cell(x, y, SMALL_RADIUS, 0);
            this->population.push_back(*temp);
        } else {
            temp = new Cell(x, y, SMALL_RADIUS, 1);
            this->population.push_back(*temp);
        }
    }
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
            fprintf(fp1, "%4d %e %5e %5e %5d\n",
                    ++curr,
                    std::get<0>(cell),
                    std::get<1>(cell),
                    std::get<2>(cell),
                    i->type());
        } fprintf(fp1, "\n\n");
    }
}
