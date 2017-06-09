/**
 * filename: Cell.h
 *
 * @author: Alberto Serrano
 *
 * purpose: Abstract Superclass: Contains all declarations, macros and most documentation
 */

#ifndef COCULTURE_CELL_H
#define COCULTURE_CELL_H

#include <tuple>
#include <math.h>
#include "randomGen.h"

class Cell {

private:
    /**
     * X and Y positions of cell
     */
    double positionX, positionY;

    /**
     * Forces along the X and Y axis of the cell
     */
    double forceX, forceY;

    /**
     * Angle the cell is facing
     */
    double angle;

    /**
     * Radius of cell (prone to change during "growth")
     */
    double radius;

    short cellType;

    /**
     * Compute the distance between two cells to see if they're "interacting"
     *
     * @param neighbor: Any other cell within the simulation
     * @return the distance
     */
    double computeDistance(class Cell neighbor, double * dx, double * dy);

    /**
     * Compute the potential between two interacting cells, while taking into account
     *     the types of each.
     *
     * @param h
     * @param type an integer within [0,2], defines the interaction type
     * @return the potential
     */
    double computeJKRPotential(double h, int type);

    /**
     * Abstract Method
     * Calculates the angle of a cell (somewhat randomly)
     */
    double computeAngle(long *idum);

public:

    Cell(double x, double y, double radius, short cellType);

    /**
     * Abstract Method
     * Compute the force between two cells, could potentially be called by computeDistance
     *     if two cells are interacting (future: make sure there's no double counting with
     *     forces).
     *     Automatically updates the force exerted on the specific cell
     *
     * @param neighbor
     */
    void computeForce(class Cell neighbor);

    /**
     * Abstract Method
     * Using the force exerted on the cell, calculate the future position and move the
     *     cell accordingly.
     */
    void move(double dt, float R);

    /**
     * Abstract Method
     * Find if the cell is healthy or cancerous (unhealthy)
     *
     * @return 0 is healthy, 1 if unhealthy
     */
    short type();

    /**
     * Change the radius of the cell by 'rate' amount
     *
     * @param rate
     */
    void modGrowth(double rate);

    /**
     * Getter for position and angle
     *
     * @return a tuple with the x, y positions and and cell's angle
     */
    std::tuple<double, double, double>getValues();

};

#define V0 0.4
double rc = 1.0;
double dcoef_ang = 0.005;       //angular diffusion coefficient
double facang = sqrt(2*dcoef_ang * 0.001); ///find better way to import DT

/* contact types (3): 0 -> HH, 1 -> HU, 2 -> UU */
double A[3] = {30.0, 15.0, 20.0};
double B[3] = {11.0, 4.50, 7.00};

#endif //COCULTURE_CELL_H
