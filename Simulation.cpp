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
//    this->population = class Cell[N];

}

void Simulation::grow() {
    vector<Cell>::iterator it;
    for(it = this->population.begin(); it != this->population.end(); ++it) {
        it->modGrowth( GROWTH_RATE );
    }
}

void Simulation::populate() {
    double x, y;

    for( int i = 0; i < N; i++ ) {
        x = this->radius * ran2(&seed);
        y = this->radius * ran2(&seed);
        Cell * temp;

        switch( i%2 ) { ///Needs to be modified to have proper ratio of healthy to unhealthy cells

            case -1: ///Purposefully not allowing unhealthy cells to be generated (should be 0)
                temp = new Unhealthy(x,y,SMALL_RADIUS);
                this->population.push_back(*temp);
//                this->population.insert(this->population.begin(), new Unhealthy(x, y, SMALL_RADIUS));
                break;

            case 1:
                temp = new Healthy(x,y,SMALL_RADIUS);
                this->population.push_back(*temp);
//                this->population.insert(this->population.begin(), new Healthy(x, y, SMALL_RADIUS));
                break;

            default:
                break;
        }
    }
}

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
            i->move();
        }

        t += DT;
        ///Need to find place to increment t and implement prints to file
    }

}

void Simulation::toString() {

}
