# Table of Contents

1.  [Introduction](#orgc417155)
2.  [Dependencies](#orgcf2d0e6)
    1.  [Python](#orga66e856)
    2.  [C++](#orgfff493c)
        1.  [Cmake >=3.8](#orgb2ea5f4)
        2.  [make](#orga08e91e)
        3.  [Boost >= 1.69](#orgf35d9ba)
    3.  [Documentation](#orgd4ee22b)
3.  [Compiling](#org09bcc80)



<a id="orgc417155"></a>

# Introduction

This repository contains two implementations of the Monte Carlo Tree
Search UCT algorithm for single- and two-player environments.

A python implementation is rooted in MCTS\_Prototyping

A C++ implementation is rooted in MCTS

Both implementations are intended to be generic enough that a user can
derive their own environment from the base classes provided and solve
that environment with the core engine.


<a id="orgcf2d0e6"></a>

# Dependencies

As this is being developed on Linux, only Linux instructions will be
provided as of now. However, this should be applicable to other
platforms as well.


<a id="orga66e856"></a>

## Python

The python code is straight forward; install numpy and anytree, and
you should be good to go.


<a id="orgfff493c"></a>

## C++

Current requirements are as follows:


<a id="orgb2ea5f4"></a>

### Cmake >=3.8


<a id="orga08e91e"></a>

### make


<a id="orgf35d9ba"></a>

### Boost >= 1.69

This should all be available in your distribution's package manager.
If you wish to use a local installation of boost in a non-standard
install location, you can set the environment variable
BOOST\_ROOT="/path/to/your/boost/root", and the CMake script should
prioritize that install.


<a id="orgd4ee22b"></a>

## Documentation

This project uses Doxygen to generate documentation. If you wish to
build the documentation pages, please install Doxygen and Graphviz.


<a id="org09bcc80"></a>

# Compiling

Compiling the C++ code is straight forward after installing the above dependencies;

`cd MCTS`

`cmake .`

`make`

The binaries will be in `GIT_ROOT/MCTS/build/bin`

Optionally, if you wish to build the documentation:

`make doc`

Html and latex documentation will be generated in `GIT_ROOT/doc`
