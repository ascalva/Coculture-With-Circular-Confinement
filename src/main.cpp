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
#include <getopt.h>

#include "../include/Simulation.h"

using namespace std;

//int Simulation::R;
int main( int argc, char * argv[] ) {

    int opt;
    int tmpsize = 0;

    while( (opt = getopt( argc, argv, "Hv:p:R:") ) != -1 ) {
        switch( opt ) {
            case 'H':
//                displayHelp();
                return 0;
            case 'v':
//                tmpsize = (double) strtol(optarg, NULL, 10 );

                break;
            case 'p':

                break;
            case 'R':
                tmpsize = (int) strtol(optarg, NULL, 10 );
        }
    }

    Simulation coCulture;
    coCulture.populate();
    coCulture.run();

    return 0;
}
