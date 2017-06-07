/**
 * filename: Healthy.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose: Subclass of the Cell superclass, inherits all its methods and implements
 *          all virtual (abstract) methods.
 */

#include "Healthy.h"

Healthy::Healthy(double x, double y, double radius)
        : Cell(x, y, radius)
{}

void Healthy::computeForce(class Cell neighbor) {

}

void Healthy::move() {

}

void Healthy::computeAngle() {

}

short Healthy::type() {
    return 1;
}