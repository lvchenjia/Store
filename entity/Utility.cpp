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

vector<string> Utility::split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}