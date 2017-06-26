/**
 * filename: main.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose: Simulate the interactions between two different types of cells by creating an instance of the
 *          Simulation class and running a couple of its public methods.
 *
 *          TODO: Add ability to change program parameters through different command line arguments
 */

#include <iostream>

#include "../include/Simulation.h"

using namespace std;

int main( void ) {

    Simulation coCulture;
    coCulture.populate();
    coCulture.run();

    return 0;
}
