//
// Created by Horse on 2022/11/22.
//

#ifndef STORE_SHOWTABLE_H
#define STORE_SHOWTABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

class ShowTable {
public:
    static void printTable(vector<vector<string>> table);
    static void printTable(vector<vector<string>> table, int colwidth);
    static int calcLength(string str);
    static int countChinese(string str);
};


#endif //STORE_SHOWTABLE_H
