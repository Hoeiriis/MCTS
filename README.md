# Table of Contents

1.  [Introduction](#org77c0a10)
2.  [Dependencies](#org00301ce)
    1.  [Python](#orge1df5b1)
    2.  [C++](#org7764326)
        1.  [Cmake >=3.8](#org27264ae)
        2.  [make](#org470f8a4)
        3.  [Boost >= 1.69](#org9390698)
    3.  [Documentation](#org7dcab04)
3.  [Compiling](#orga1eb4a2)



<a id="org77c0a10"></a>

# Introduction

This repository contains two implementations of the Monte Carlo Tree
Search UCT algorithm for single- and two-player environments.

A python implementation is rooted in MCTS\_Prototyping
A C++ implementation is rooted in MCTS

Both implementations are intended to be generic enough that a user can
derive their own environment from the base classes provided and solve
that environment with the core engine.


<a id="org00301ce"></a>

# Dependencies

As this is being developed on Linux, only Linux instructions will be
provided as of now. However, this should be applicable to other
platforms as well.


<a id="orge1df5b1"></a>

## Python

The python code is straight forward; install numpy and anytree, and
you should be good to go.


<a id="org7764326"></a>

## C++

Current requirements are as follows:


<a id="org27264ae"></a>

### Cmake >=3.8


<a id="org470f8a4"></a>

### make


<a id="org9390698"></a>

### Boost >= 1.69

This should all be available in your distribution's package manager.
If you wish to use a local installation of boost in a non-standard
install location, you can set the environment variable
BOOST\_ROOT="/path/to/your/boost/root", and the CMake script should
prioritize that install.


<a id="org7dcab04"></a>

## Documentation

This project uses Doxygen to generate documentation. If you wish to
build the documentation pages, please install Doxygen and Graphviz.


<a id="orga1eb4a2"></a>

# Compiling

Compiling the C++ code is straight forward after installing the above dependencies;

`cd MCTS`

`cmake .`

`make`

The binaries will be in `GIT_ROOT/MCTS/build/bin`

Optionally, if you wish to build the documentation:

`make doc`

Html and latex documentation will be generated in `GIT_ROOT/doc`
