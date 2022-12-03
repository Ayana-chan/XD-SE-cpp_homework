#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <string>

using namespace std;

namespace Error {
    extern int no_of_errors;
    extern double error(const std::string& s);
}

#endif
