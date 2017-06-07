/**
 * filename: Simulation.h
 *
 * @author: Alberto Serrano
 *
 * purpose:
 */

#ifndef COCULTURE_SIMULATION_H
#define COCULTURE_SIMULATION_H

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <list>
#include "Cells/Cell.h"
#include "Cells/Healthy.h"
#include "Cells/Unhealthy.h"
#include "Cells/randomGen.h"


class Simulation {

private:
    FILE * fp1;
    float radius;
    int N;
    int N2;
    int N1;
    std::list<Cell*> population;

public:
    Simulation(FILE * fp1);

    void init();

    void populate();

    void run();

    void toString();
};

#define R 9
#define PHI 1.4
#define DT 0.001
#define TMAX 2000.0
#define RATIO 1.0


#endif //COCULTURE_SIMULATION_H
