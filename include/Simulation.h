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
#include <vector>

#include "Cell.h"
#include "randomGen.h"

using namespace std;

class Simulation {

private:

    /**
     * Radius of circular confinement
     */
    float radius;

    /**
     * Total number of cells
     */
    int totalCells;

    /**
     * Number of unhealthy cells
     */
    int unealthyCells;

    /**
     * Number of healthy cells
     */
    int healthyCells;

    /**
     * Container for all cell objects
     */
    vector<Cell*> population;

    class randomGen * randomGen = nullptr;

    bool checkNeighbors(double x, double y);


public:

    Simulation();

    /**
     * Populate circular confinement with infinitesimally sized cells, this makes sure that
     *     there is no overlap between any cells
     */
    void populate();

    /**
     * Run the simulation (once all cells are fully "grown") for a period of TMAX, letting
     *     time increments be done by DT
     */
    void run();

};

#define R 9
#define PHI 0.81
#define DT 0.001
#define TMAX 20.0
#define RATIO 1.0 //Ratio between healthy and unhealthy
#define INIT_MIN_SPACING 0.7

#define FINAL_RADIUS 0.5

#define SEED1 -8838317
#define SEED2 -1872371

#endif //COCULTURE_SIMULATION_H
