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

void displayHelp() {
    cout << "usage: ./coculture [options]\n"
         << "Program will run with default settings unless otherwise specified\n"
         << "Simulation Configuration Options:\n"
         << " -H  # View simulation options and quit\n"
         << " -vN # Self propulsion speed\n"
         << " -RN # Set confinement radius\n"
         << " -rN # Set cell radius\n"
         << " -pN # Set value for packing fraction\n"
         << " -cN # Set cell ratio healthy:cancer\n"
         << " -dN # Set value for dt (time step)\n"
         << " -tN # Set max amount of time for which program runs\n"
         << endl;
}

int main( int argc, char * argv[] ) {

    int opt;
    int tmpsize = 0;
    double tmp = 0;

    while( (opt = getopt( argc, argv, "Hv:p:R:r:d:t:") ) != -1 ) {
        switch( opt ) {
            case 'H':
                displayHelp();
                return 0;
            case 'v':
                tmp = (double) strtol(optarg, NULL, 10 );
                if( tmp >= 0 ) {
                    V0 = tmp;
                } break;
            case 'p':
                tmp = (double) strtol(optarg, NULL, 10 );
                if( 0 <= tmp && tmp <= 2 ) {
                    RATIO = (float) tmp;
                } break;
            case 'R':
                tmpsize = (int) strtol(optarg, NULL, 10 );
                if( tmpsize > 0 ) {
                    confinementRadius = tmpsize;
                } break;
            case 'r':
                tmp = (double) strtol(optarg, NULL, 10 );
                if( 0 < tmp && tmp < confinementRadius ) {
                    cellRadius = (float) tmp;
                } break;
            case 'd':
                tmp = (double) strtol(optarg, NULL, 10 );
                if( 0 < tmp && tmp < TMAX ) {
                    DT = tmp;
                } break;
            case 't':
                tmp = (double) strtol(optarg, NULL, 10 );
                if( tmp > 0 ) {
                    TMAX = tmp;
                } break;
            default:
                displayHelp();
                return 0;
        }
    }

    Simulation coCulture;
    coCulture.populate();
    coCulture.run();

    return 0;
}
