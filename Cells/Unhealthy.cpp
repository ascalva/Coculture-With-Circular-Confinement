/**
 * filename: Unhealthy.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose: Subclass of the Cell superclass, inherits all its methods and implements
 *          all virtual (abstract) methods.
 */

#include "Unhealthy.h"

Unhealthy::Unhealthy(double x, double y, double radius)
        : Cell(x, y, radius)
{}

void Unhealthy::computeForce(class Cell neighbor) {

}

void Unhealthy::move() {

}

void Unhealthy::computeAngle() {

}

short Unhealthy::type() {
    return 0;
}