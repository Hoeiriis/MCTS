# Table of Contents

1.  [Introduction](#orgf0a6cc7)
2.  [Dependencies](#orgf83bd06)
    1.  [Python](#orgd54e894)
    2.  [C++](#org92febb7)
        1.  [Cmake >=3.8](#orgc9159f7)
        2.  [make](#org66308e1)
        3.  [Boost >= 1.69](#org8ffc9f2)
    3.  [Documentation](#orgfe55809)
3.  [Compiling](#orgb0bf28f)



<a id="orgf0a6cc7"></a>

# Introduction

This repository contains two implementations of the Monte Carlo Tree
Search UCT algorithm for single- and two-player environments.

A python implementation is rooted in MCTS\\\_Prototyping
A C++ implementation is rooted in MCTS

Both implementations are intended to be generic enough that a user can
derive their own environment from the base classes provided and solve
that environment with the core engine.


<a id="orgf83bd06"></a>

# Dependencies

As this is being developed on Linux, only Linux instructions will be
provided as of now. However, this should be applicable to other
platforms as well.


<a id="orgd54e894"></a>

## Python

The python code is straight forward; install numpy and anytree, and
you should be good to go.


<a id="org92febb7"></a>

## C++

Current requirements are as follows:


<a id="orgc9159f7"></a>

### Cmake >=3.8


<a id="org66308e1"></a>

### make


<a id="org8ffc9f2"></a>

### Boost >= 1.69

This should all be available in your distribution's package manager.
If you wish to use a local installation of boost in a non-standard
install location, you can set the environment variable
BOOST\_ROOT="/path/to/your/boost/root", and the CMake script should
prioritize that install.


<a id="orgfe55809"></a>

## Documentation

This project uses Doxygen to generate documentation. If you wish to
build the documentation pages, please install Doxygen and Graphviz.


<a id="orgb0bf28f"></a>

# Compiling

Compiling the C++ code is straight forward after installing the above dependencies;

`cd MCTS`

`cmake .`

`make`

The binaries will be in `GIT_ROOT/MCTS/build/bin`

Optionally, if you wish to build the documentation:

`make doc`

Html and latex documentation will be generated in `GIT_ROOT/doc`
