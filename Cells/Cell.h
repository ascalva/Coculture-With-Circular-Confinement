/**
 * filename: Cell.h
 *
 * @author: Alberto Serrano
 *
 * purpose: Abstract Superclass: Contains all declarations, macros and most documentation
 */

#ifndef COCULTURE_CELL_H
#define COCULTURE_CELL_H

#include "randomGen.h"

class Cell {

protected:
    double positionX, positionY;
    double forceX, forceY;
    double angle;
    double radius;

public:

    Cell(double x, double y, double radius);

    /**
     * Compute the distance between two cells to see if they're "interacting"
     *
     * @param neighbor: Any other cell within the simulation
     * @return the distance
     */
    double computeDistance(class Cell neighbor);

    /**
     * Abstract Method
     * Compute the force between two cells, could potentially be called by computeDistance
     *     if two cells are interacting (future: make sure there's no double counting with
     *     forces).
     *     Automatically updates the force exerted on the specific cell
     *
     * @param neighbor
     */
    virtual void computeForce(class Cell neighbor) = 0;

    /**
     * Abstract Method
     * Using the force exerted on the cell, calculate the future position and move the
     *     cell accordingly.
     */
    virtual void move() = 0;

    /**
     * Abstract Method
     * Calculates the angle of a cell (somewhat randomly)
     */
    virtual void computeAngle() = 0;

    /**
     * Abstract Method
     * Find if the cell is healthy or cancerous (unhealthy)
     *
     * @return true (1) is healthy, false (0) if unhealthy
     */
    virtual short type() = 0;

    void modGrowth(double rate);

};


double rc = 1.0;

/* contact types (3): 0 -> HH, 1 -> HU, 2 -> UU */
double A[3] = {30.0, 15.0, 20.0};
double B[3] = {11.0, 4.50, 7.00};


#endif //COCULTURE_CELL_H
