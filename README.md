Role of self-propulsion in cell segregation of 2D circularly confined co-culture
================================================================================

**Author**: Alberto Serrano (RIT undergraduate)

**Adviser**: Dr. Moumita Das (Assistant Professor of Physics at RIT)

## Abstract
Cell segregation is a key process during tissue morphogenesis in embryonic development and tumor formation. That is why a deeper understanding into the role of self-propulsion and contact interactions is needed, while using a simple model. A computational approach was taken to study the problem more closely by applying our model to a 2D co-culture with circular confinement. Core-shell structures were not observed and it was shown that cancer cells move faster than healthy cells as seen in experiments.

## Running the simulation
1. Run `make` to generate executable file.
    - Remove the compilation flag `-DCMD_OUT` from makefile if you want the data to be outputted to a file (1.out).
2. `defaults.cpp` can be modified to change simulation parameters.
3. Run `./coculture` to start simulation.
4. Run `./run.sh N` from within the plots directory to animate the output, where N is the number of frames.
5. (Optional) Use `make clean` and `make cleanjunk` to remove .o files and excess images.
