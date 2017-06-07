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

}

void Simulation::populate() {
    double x, y;

    while( int i = 0 < N) {
        x =
        i++;
    }
}

void Simulation::run() {

}

void Simulation::toString() {

}
