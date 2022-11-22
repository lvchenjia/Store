//
// Created by Horse on 2022/11/22.
//

#include "Utility.h"

string Utility::doubleToString(double d, int precision) {
    stringstream ss;
    string str;
    ss << setprecision(precision) << d;
    return ss.str();
}