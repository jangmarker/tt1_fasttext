#include "cli.h"

#include <iostream>

int main(int argc, char** argv) {
    return cli(argc, argv, std::cout);
}