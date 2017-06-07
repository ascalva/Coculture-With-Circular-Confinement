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
//#include <list>
//#include <altivec.h>
#include <vector>
#include "Cells/Cell.h"
#include "Cells/Healthy.h"
#include "Cells/Unhealthy.h"
#include "Cells/randomGen.h"

using namespace std;

class Simulation {

private:
    FILE * fp1;
    float radius;
    int N;
    int N2;
    int N1;
    vector<Cell> population;

public:
    Simulation(FILE * fp1);

    void populate();

    void grow();

    void run();

    void toString();
};

#define R 9
#define PHI 1.4
#define DT 0.001
#define TMAX 2000.0
#define RATIO 1.0

#define SMALL_RADIUS 0.001
#define GROWTH_RATE 0.001

#endif //COCULTURE_SIMULATION_H
