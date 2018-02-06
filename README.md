[![Build status](https://ci.appveyor.com/api/projects/status/2t2swcj87h022d2l?svg=true)](https://ci.appveyor.com/project/jangmarker/tt1-fasttext) [![Build Status](https://travis-ci.org/jangmarker/tt1_fasttext.svg?branch=master)](https://travis-ci.org/jangmarker/tt1_fasttext) [![codecov](https://codecov.io/gh/jangmarker/tt1_fasttext/branch/master/graph/badge.svg)](https://codecov.io/gh/jangmarker/tt1_fasttext)

# TT1 Fast Text - Lösung Jan Marker

## Dependencies
The program is mainly based on the C++ standard library, except for:

- Catch (http://catch-lib.net/) - a unit testing framework for C++
- CLI11 (https://github.com/CLIUtils/CLI11) - framework to parse CLI parameters
- pugixml (https://pugixml.org/) - to parse XML

The dependencies are included in `3rdparty/` and are to no concern of a user.

The code uses features of C++17, including:

- string_view
- experimental/filesystem

It was tested with Visual Studio 15.0 2017 and GCC 7.2.1.

## Usage

The program does not respond to parameters, it expects the `*.tei` files to be placed in `./data` following the following pattern: `<category name>_(test|train).tei` (as provided for this task).

For three variants it generates two files per variant, one called `<variant name>.train` and one called `<variant name>.test`.

## Code Organization

### `clip.{h,cpp}` `main.{cpp}`

Main program, uses `tei_directory` to read the input data from files in `./dat` to write the variations.

### `tei_directory.{h,cpp}`

On construction reads and parses all `*.tei` files in the given directory. Extracts category and purpose (test/train) from file name.

`writeTrainingFile` and `writeTestFile` can be used to write the input files for fasttext for training and testing respectively. These functions take a `FeatureExtractor`:

C++ callable that takes a `Word` type and returns a `std::vector<std::string_view>` (`string_view` into the members of `Word`). For examples see `cli.cpp`. It internally uses `token_extractor` and `data_file`. The `FeatureExtractor` is directly passed to `data_file`.

### `data_file.{h,cpp}`

Writes a fast text output file which it represents. It receives `TeiFileParsed` (also defined here) and transforms them using a given `FeatureExtractor` to lines of the format `__label__<label> <joined by space list of extracted tokens>` (fasttext format). See `tei_directory` for a description of `FeatureExtractor`.

It internally uses `token_extractor` to operate on the XML tree structure (provided by `pugi::xml_document`). For `token_extractor` it does provide it's own `DocumentHandler` (to create newlines in the target data file) and wraps `FeatureExtractor` into a `WordHandler` compatible with `token_extractor`.

### `token_extractor.{h,cpp}`

Implements a `pgui::xml_tree_walker`. For XML nodes of the name "TEI" it calls the provided `DocumentHandler` (without parameter), for nodes of name "w" it calls the provided `WordHandler` with a parameter of type `Word`. `Word` contains the original word and the XML attributes to the "w" tag (e.g. gender, word type, lemma).