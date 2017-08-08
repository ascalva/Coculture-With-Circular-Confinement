Coculture With Circular Confinement
===================================

**Author**: Alberto Serrano

## Running the simulation
1. Run `make` to get an executable file.
    - Remove the compilation flag `-DCMD_OUT` from makefile if you want the data to be outputted to a file (1.out).
2. `defaults.cpp` can be modified to change simulation parameters.
3. Run `./coculture` to start simulation.
4. Run `./run.sh N` from within the plots directory to animate the output, where N is the number of frames.
5. (Optional) Use `make clean` and `make cleanjunk` to remove .o files and excess images.
