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

#include "Cells/Cell.h"
#include "Cells/Healthy.h"
#include "Cells/Unhealthy.h"
#include "Cells/randomGen.h"

using namespace std;

class Simulation {

private:
    FILE * fp1;

    /**
     * Radius of circular confinement
     */
    float radius;

    /**
     * Total number of cells
     */
    int N;

    /**
     * Number of unhealthy cells
     */
    int N2;

    /**
     * Number of healthy cells
     */
    int N1;

    /**
     * Container for all cell objects
     */
    vector<Cell> population;

public:
    Simulation(FILE * fp1);

    /**
     * Populate circular confinement with infinitesimally sized cells, this makes sure that
     *     there is no overlap between any cells
     */
    void populate();

    /**
     * Grow all cells within the confinement to their proper sizes (using proper interaction
     *     properties). Purpose of "growing" cells is to be able to place them randomly within
     *     the confined area without overlap; method of placement is prone to changed if better
     *     method arises.
     */
    void grow();

    /**
     * Run the simulation (once all cells are fully "grown") for a period of TMAX, letting
     *     time increments be done by DT
     */
    void run();

    /**
     * Function to print x and y positions with angle of cells to a specified file
     */
    void toString();
};

#define R 9
#define PHI 1.4
#define DT 0.001
#define TMAX 2000.0
#define RATIO 1.0 //Ratio between healthy and unhealthy

#define SMALL_RADIUS 0.001 //"Infinitesimal" size
#define GROWTH_RATE 0.001

#endif //COCULTURE_SIMULATION_H
