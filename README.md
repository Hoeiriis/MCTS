# Table of Contents

1.  [Introduction](#orga2eb874)
2.  [Dependencies](#orgbfa77d9)
    1.  [Python](#orgda8ec76)
    2.  [C++](#org710582d)
        1.  [Cmake >=3.8](#org514dabe)
        2.  [make](#org4c97949)
        3.  [Boost >= 1.69](#org15f49e0)
    3.  [Documentation](#org16296eb)
    4.  [C++ tests](#orgdd85980)
3.  [Compiling](#orgf3b098b)
4.  [Writing documentation](#orgc31acd4)
5.  [Writing tests](#org0d17d3f)



<a id="orga2eb874"></a>

# Introduction

This repository contains two implementations of the Monte Carlo Tree
Search UCT algorithm for single- and two-player environments.

A python implementation is rooted in MCTS\_Prototyping

A C++ implementation is rooted in MCTS

Both implementations are intended to be generic enough that a user can
derive their own environment from the base classes provided and solve
that environment with the core engine.


<a id="orgbfa77d9"></a>

# Dependencies

As this is being developed on Linux, only Linux instructions will be
provided as of now. However, this should be applicable to other
platforms as well.


<a id="orgda8ec76"></a>

## Python

The python code is straight forward; install numpy and anytree, and
you should be good to go.


<a id="org710582d"></a>

## C++

Current requirements are as follows:


<a id="org514dabe"></a>

### Cmake >=3.8


<a id="org4c97949"></a>

### make


<a id="org15f49e0"></a>

### Boost >= 1.69

This should all be available in your distribution's package manager.
If you wish to use a local installation of boost in a non-standard
install location, you can set the environment variable
BOOST\_ROOT="/path/to/your/boost/root", and the CMake script should
prioritize that install.


<a id="org16296eb"></a>

## Documentation

This project uses Doxygen to generate documentation. If you wish to
build the documentation pages, please install Doxygen and Graphviz.


<a id="orgdd85980"></a>

## C++ tests

CMake clones googletests from the official git repo and installs it in
`GIT_ROOT/External_Libs/GTest` Currently, GTest will not be installed
AND generate tests on the first run. When building from a clean clone
you should run the following sequence of commands before the tests
will be compiled:

1.  cmake
2.  make
3.  cmake
4.  make
5.  make test

After this sequence of commands as been run, the tests will be
compiled properly on each invocation of make.


<a id="orgf3b098b"></a>

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


<a id="orgc31acd4"></a>

# Writing documentation

Please document your files, classes, and functions where it isn't
self explanatory. Doxygen comments should be in the header files,
and not in the .cpp files. That way, users of the library do not
need to use the actual source files in order to access the
documentation, and can therefore use precompiled binaries instead of
compiling it themselves, and editors only need to access the header
files being included in order to provide in-editor documentation.
Doxygen will not include documentation for your functions if the
encapsulating class is not documented, and it will not include
documentation for your class if the containing file is not
annotated. See `TicTacToeEnvironment.h` or
`GIT_ROOT/MCTS/src/doxygen_example.cpp` for an example of the
syntax.

See <http://www.doxygen.nl/manual/> for details.


<a id="org0d17d3f"></a>

# Writing tests

You can use `GIT_ROOT/MCTS/test/test_environments` as a template for
setting up your tests.

In order to add tests for a feature:

1.  Create a subdirectory for the feature `GIT_ROOT/MCTS/test/`, e.g.
    `GIT_ROOT/MCTS/test/my_awesome_feature/`
2.  Add `add_subdirectory(my_awesome_feature)` to
    `GIT_ROOT/MCTS/test/CMakeLists.txt`
3.  Add test source files for your feature in your directory, e.g. test\_my\_awesome\_feature.cpp.

Include GTest and necessary headers, (`#include <gtest/gtest.h>`) and
start writing tests. GTest defines a number of macros. For most tests
you just need `TEST`, `EXPECT_EQ`, and `EXPECT_DOUBLE_EQ`. Define a
test with

~TEST(NameOfFunctionBeingTested, PropertyBeingTested){
EXPECT\_EQ(function\_output, expected\_output);
}~

Add your source file as an executable target in CMakeLists.txt as usual,
and link the target against GTest and the feature itself if applicable:

`add_executable(test_my_awesome_feature test_my_awesome_feature.cpp`

`target_link_libraries(test_my_awesome_feature GTest::GTest GTest::Main my_awesome_feature)`

And then have gtest detect the test cases and add them:

`gtest_add_tests(TARGET test_my_awesome_feature)`

For details and more advanced use, check the official documentation:

[Google test in CMake](<https://cmake.org/cmake/help/v3.15/module/GoogleTest.html>)

[Google test primer](<https://github.com/google/googletest/blob/master/googletest/docs/primer.md>)

[Google mock primer](<https://github.com/google/googletest/blob/master/googlemock/README.md>)
