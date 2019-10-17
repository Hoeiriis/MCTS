# Table of Contents

1.  [Introduction](#org9ead8c0)
2.  [Dependencies](#org6a4c09a)
    1.  [Python](#org0196971)
    2.  [C++](#org4e9291d)
        1.  [Cmake >=3.8](#org1ef5b6d)
        2.  [make](#org5d7e3c3)
        3.  [Boost >= 1.69](#org04db1ef)
    3.  [Documentation](#org8bdb8cd)
3.  [Compiling](#org4bd0a95)


<a id="org9ead8c0"></a>

# Introduction

This repository contains two implementations of the Monte Carlo Tree
Search UCT algorithm for single- and two-player environments.

A python implementation is rooted in MCTS\\<sub>Prototyping</sub>
A C++ implementation is rooted in MCTS

Both implementations are intended to be generic enough that a user can
derive their own environment from the base classes provided and solve
that environment with the core engine.


<a id="org6a4c09a"></a>

# Dependencies

As this is being developed on Linux, only Linux instructions will be
provided as of now. However, this should be applicable to other
platforms as well.


<a id="org0196971"></a>

## Python

The python code is straight forward; install numpy and anytree, and
you should be good to go.


<a id="org4e9291d"></a>

## C++

Current requirements are as follows:


<a id="org1ef5b6d"></a>

### Cmake >=3.8


<a id="org5d7e3c3"></a>

### make


<a id="org04db1ef"></a>

### Boost >= 1.69

This should all be available in your distribution's package manager.
If you wish to use a local installation of boost in a non-standard
install location, you can set the environment variable
BOOST<sub>ROOT</sub>="/path/to/your/boost/root", and the CMake script should
prioritize that install.


<a id="org8bdb8cd"></a>

## Documentation

This project uses Doxygen to generate documentation. If you wish to
build the documentation pages, please install Doxygen and Graphviz.


<a id="org4bd0a95"></a>

# Compiling

Compiling the C++ code is straight forward after installing the above dependencies;

`cd MCTS`

`cmake .`

`make`

The binaries will be in `GIT_ROOT/MCTS/build/bin`

Optionally, if you wish to build the documentation:

`make doc`

Html and latex documentation will be generated in `GIT_ROOT/doc`
