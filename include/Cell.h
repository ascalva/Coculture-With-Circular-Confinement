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
#include "defaults.h"

class Cell {

private:

    /**
     * X and Y positions of cell
     */
    double positionX, positionY;

    /**
     * Initial position of particle (never updated)
     */
    double initX, initY;

    /**
     * Forces along the X and Y axis of the cell
     */
    double forceX, forceY;

    /**
     * Angle the cell is facing
     */
    double angle;

    /**
     * Radius of cell
     */
    double radius;

    class randomGen * randomGen = nullptr;

    /**
     * Type of cell, 0 if healthy, 1 if unhealthy (cancer)
     */
    short cellType;

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
    double computeAngle(uint16_t idum);

public:

    Cell(double x, double y, double radius, short cellType, class randomGen * ran);

    /**
     * Compute the force between two cells, could potentially be called by computeDistance
     *     if two cells are interacting (future: make sure there's no double counting with
     *     forces).
     *     Automatically updates the force exerted on the specific cell
     *
     * @param neighbor
     */
    void computeForce(class Cell * neighbor);

    /**
     * Using the force exerted on the cell, calculate the future position and move the
     *     cell accordingly.
     */
    void move(double dt, float R);

    /**
     * Find if the cell is healthy or cancerous (unhealthy)
     *
     * @return 0 is healthy, 1 if unhealthy
     */
    short type();

    /**
     * Getter for position and angle
     *
     * @return a tuple with the x, y positions and and cell's angle
     */
    std::tuple<double, double, double>getValues();

    /**
     * Computes the squared displacement of the cell (from initial position to current position)
     *
     * @return
     */
    double computeSquaredDisplacement();

    /**
     * Generate a new cell a short distance away from parent cell, pointing in the opposite direction
     *     of the parent cell's direction.
     *
     * @return The offspring to be added into collection of cells
     */
    Cell * divide();

    /**
     * Initializes the position at a certain time to start tracking mean squared displacement data
     */
    void initMSD();

};

#endif //COCULTURE_CELL_H
