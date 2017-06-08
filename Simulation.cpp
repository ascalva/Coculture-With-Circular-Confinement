/**
 * filename: Simulation.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose:
 */

#include "Simulation.h"


Simulation::Simulation(FILE * fp1)
        : fp1(fp1),
          radius(R)
{
    this->totalCells = (int) ((PHI * 4 * R * R)/M_PI);
    this->unealthyCells = (int) (this->totalCells/(1.0+RATIO));
    this->healthyCells = (int) (this->unealthyCells * RATIO);

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

        if( cellNum < this->healthyCells ) {
            temp = new Healthy(x,y,SMALL_RADIUS);
            this->population.push_back(*temp);
        } else {
            temp = new Unhealthy(x,y,SMALL_RADIUS);
            this->population.push_back(*temp);
        }
    }
}

///TODO: Reimplement in light of recent changes to Cell
void Simulation::run() {
    vector<Cell>::iterator i;
    vector<Cell>::iterator j;
    double dist;

    while(double t = 0.0 < TMAX) {
        for(i = population.begin() ; i != population.end(); ++i) {
            for(j = population.begin(); j != population.end(); ++j) {
                if( i->computeDistance( *j ) < pow(this->radius, 2) ) {
                    i->computeForce(*j); ///imp cF()
                }
            }
        }
        for(i=population.begin(); i != population.end(); ++i) {
            i->move( DT );
        }

        t += DT;
        ///Need to find place to increment t and implement prints to file
    }

}

void Simulation::toString() {

}
