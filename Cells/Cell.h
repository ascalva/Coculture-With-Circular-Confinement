/**
 * filename: Cell.h
 *
 * @author: Alberto Serrano
 *
 * purpose: Abstract Superclass: Contains all declarations, macros and most documentation
 */

#ifndef COCULTURE_CELL_H
#define COCULTURE_CELL_H

class Cell {

protected:
    double positionX, positionY;
    double forceX, forceY;
    double angle;
    float radius;

public:

    Cell(double x, double y, float radius);

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
    virtual bool type() = 0;

    /**
     * Compute a 'random' between 0 and 1
     *
     * (C) Copr. 1986-92 Numerical Recipes Software
     *
     * @param idum is the address of the seed used
     */
    double ran2(long *idum);
};

#define IM1 2147483563
#define IM2 2147483399
#define AM (1.0/IM1)
#define IMM1 (IM1-1)
#define IA1 40014
#define IA2 40692
#define IQ1 53668
#define IQ2 52774
#define IR1 12211
#define IR2 3791
#define NTAB 32
#define NDIV (1+IMM1/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

long seed = -8838317;  //use large negative integers for seeds
long seed1 = -1872371;
double rc = 1.0;

/* contact types (3): 0 -> HH, 1 -> HU, 2 -> UU */
double A[3] = {30.0, 15.0, 20.0};
double B[3] = {11.0, 4.50, 7.00};


#endif //COCULTURE_CELL_H
