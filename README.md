# Table of Contents

1.  [Introduction](#orgc1340d1)
2.  [Dependencies](#orgecab7eb)
    1.  [Python](#orgcdf007d)
    2.  [C++](#org3b9b34b)
        1.  [Cmake >=3.8](#orgbdfc723)
        2.  [make](#org33bff5e)
        3.  [Boost >= 1.69](#org2958970)
    3.  [Documentation](#orga105543)
3.  [Compiling](#orgbcac03f)


<a id="orgc1340d1"></a>

# Introduction

This repository contains two implementations of the Monte Carlo Tree
Search UCT algorithm for single- and two-player environments.

A python is based in MCTS<sub>Prototyping</sub>
A C++ implementation is based in MCTS

Both implementations are intended to be generic enough that a user can
derive their own environment from the base classes provided and solve
that environment with the core engine.


<a id="orgecab7eb"></a>

# Dependencies

As this is being developed on Linux, only Linux instructions will be
provided as of now. However, this should be applicable to other
platforms as well.


<a id="orgcdf007d"></a>

## Python

The python code is straight forward; install numpy and anytree, and
you should be good to go.


<a id="org3b9b34b"></a>

## C++

Current requirements are as follows:


<a id="orgbdfc723"></a>

### Cmake >=3.8


<a id="org33bff5e"></a>

### make


<a id="org2958970"></a>

### Boost >= 1.69

This should all be available in your distribution's package manager.
If you wish to use a local installation of boost in a non-standard
install location, you can set the environment variable
BOOST<sub>ROOT</sub>="/path/to/your/boost/root", and the CMake script should
prioritize that install.


<a id="orga105543"></a>

## Documentation

This project uses Doxygen to generate documentation. If you wish to
build the documentation pages, please install Doxygen and Graphviz.


<a id="orgbcac03f"></a>

# Compiling

Compiling the C++ code is straight forward after installing the above dependencies;

`cd MCTS`

`cmake .`

`make`

The binaries will be in `GIT_ROOT/MCTS/build/bin`

Optionally, if you wish to build the documentation:

`make doc`

Html and latex documentation will be generated in `GIT_ROOT/doc`
