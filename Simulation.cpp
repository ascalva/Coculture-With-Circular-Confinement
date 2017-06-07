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
    this->N = (int) ((PHI * 4 * R * R)/M_PI);
    this->N2 = (int) (N/(1.0+RATIO));
    this->N1 = (int) (N2 * RATIO);

}

void Simulation::init() {
    for(Cell * i : this->population) {
        i->modGrowth( GROWTH_RATE );
    }
}

void Simulation::populate() {
    double x, y;

    for( int i = 0; i < N; i++ ) {
        x = this->radius * ran2(&seed);
        y = this->radius * ran2(&seed);

        switch( i%2 ) {

            case -1: ///Purposefully not allowing unhealthy cells to be generated (should be 0)
                this->population.insert(this->population.begin(), new Unhealthy(x, y, SMALL_RADIUS));
                break;

            case 1:
                this->population.insert(this->population.begin(), new Healthy(x, y, SMALL_RADIUS));
                break;

            default:
                break;
        }
    }
}

void Simulation::run() {

}

void Simulation::toString() {

}
