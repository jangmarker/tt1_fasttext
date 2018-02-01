[![Build status](https://ci.appveyor.com/api/projects/status/2t2swcj87h022d2l?svg=true)](https://ci.appveyor.com/project/jangmarker/tt1-fasttext) [![Build Status](https://travis-ci.org/jangmarker/tt1_fasttext.svg?branch=master)](https://travis-ci.org/jangmarker/tt1_fasttext) [![codecov](https://codecov.io/gh/jangmarker/tt1_fasttext/branch/master/graph/badge.svg)](https://codecov.io/gh/jangmarker/tt1_fasttext)

# TT1 Fast Text - Lösung Jan Marker

## Dependencies
The program is mainly based on the C++ standard library, except for:

- Catch (http://catch-lib.net/) - a unit testing framework for C++
- CLI11 (https://github.com/CLIUtils/CLI11) - framework to parse CLI parameters
- pugixml (https://pugixml.org/) - to parse XML

The two dependencies are included in `3rdparty/` and are to no concern of a user.

The code uses features of C++17, including:

- string_view
- experimental/filesystem

It was tested with Visual Studio 15.0 2017 and GCC 7.2.1.