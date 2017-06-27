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
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Cell.h"
#include "randomGen.h"
#include "defaults.h"

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

    /**
     * The only instance of the randomGen class
     */
    class randomGen * randomGen = nullptr;

    /**
     * Helper function to populate(), used to check the distance between two particles by checking
     *     if the provided distance is too close to another known position of a cell
     *
     * @param x Potential x value of the position
     * @param y Potential y value of the position
     * @return true if cells are spaced enough apart, false otherwise
     */
    bool checkNeighbors(double x, double y);

    /**
     * Prints all the relevant metadata of the simulation, such as cell width, number of each type
     *     of cell, etc to an external file called "meta.dat"
     */
    void printMeta();


public:

    //Constructor
    Simulation();

    /**
     * Populate circular confinement with infinitesimally sized cells, this makes sure that
     *     there is no overlap between any cells
     */
    void populate();

    /**
     * Run the simulation for a period of TMAX, letting time increments be done by DT. Prints all relevant
     *     data into three files:
     *
     *     coculture.dat:
     *         Cell data: x,y,theta,type
     *
     *     meta.dat:
     *         Ratio 1:1
     *         Number of cells
     *         Packing fraction
     *         Time passed
     *         Cell radius
     *         Confinement radius
     *
     *     meanSqrtDisp.dat:
     *         Format: time x-msq y-msq
     *         Used to plot the mean squared displacement of each type of cell
     */
    void run();

};

#endif //COCULTURE_SIMULATION_H
