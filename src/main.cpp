/**
 * filename: main.cpp
 *
 * @author: Alberto Serrano
 *
 * purpose: Simulate the interactions between two different types of cells by creating an instance of the
 *          Simulation class and running a couple of its public methods.
 *
 */

#include <iostream>
#include <getopt.h>

#include "../include/Simulation.h"
#include "../include/defaults.h"

using namespace std;


int main( int argc, char * argv[] ) {

    Simulation coCulture;
    coCulture.populate();
    coCulture.run();

    return 0;
}
