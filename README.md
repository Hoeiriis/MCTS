# Table of Contents

1.  [Introduction](#orgbc5476a)
2.  [Dependencies](#orgbb47b02)
    1.  [Python](#org8b2113f)
    2.  [C++](#org243ebe7)
        1.  [Cmake >=3.8](#org57b278a)
        2.  [make](#orgd980967)
        3.  [Boost >= 1.69](#org2dd502b)
    3.  [Documentation](#orgbd74fda)
    4.  [C++ tests](#orgadb7f7e)
3.  [Compiling](#org89ce5fb)



<a id="orgbc5476a"></a>

# Introduction

This repository contains two implementations of the Monte Carlo Tree
Search UCT algorithm for single- and two-player environments.

A python implementation is rooted in MCTS\_Prototyping

A C++ implementation is rooted in MCTS

Both implementations are intended to be generic enough that a user can
derive their own environment from the base classes provided and solve
that environment with the core engine.


<a id="orgbb47b02"></a>

# Dependencies

As this is being developed on Linux, only Linux instructions will be
provided as of now. However, this should be applicable to other
platforms as well.


<a id="org8b2113f"></a>

## Python

The python code is straight forward; install numpy and anytree, and
you should be good to go.


<a id="org243ebe7"></a>

## C++

Current requirements are as follows:


<a id="org57b278a"></a>

### Cmake >=3.8


<a id="orgd980967"></a>

### make


<a id="org2dd502b"></a>

### Boost >= 1.69

This should all be available in your distribution's package manager.
If you wish to use a local installation of boost in a non-standard
install location, you can set the environment variable
BOOST\_ROOT="/path/to/your/boost/root", and the CMake script should
prioritize that install.


<a id="orgbd74fda"></a>

## Documentation

This project uses Doxygen to generate documentation. If you wish to
build the documentation pages, please install Doxygen and Graphviz.


<a id="orgadb7f7e"></a>

## C++ tests

CMake clones googletests from the official git repo and installs it in `GIT_ROOT/External_Libs/GTest`


<a id="org89ce5fb"></a>

# Compiling

Compiling the C++ code is straight forward after installing the above dependencies;

`cd MCTS`

`cmake .`

`make`

The binaries will be in `GIT_ROOT/MCTS/build/bin`

Optionally, if you wish to build the documentation:

`make doc`

Html and latex documentation will be generated in `GIT_ROOT/doc`

CMake builds test unless explicitly told otherwise (`cmake . -DTESTING=NO`)
Run tests with

`make test`
