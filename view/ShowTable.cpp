//
// Created by Horse on 2022/11/22.
//

#include <sstream>
#include "ShowTable.h"

void ShowTable::printTable(vector<vector<string>> table, int colwidth) {
    int row = table.size();
    int col = table[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << table[i][j];
            int len = calcLength(table[i][j]);
            for (int k = 0; k < colwidth - len; k++) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void ShowTable::printTable(vector<vector<string>> table) {
    int row = table.size();
    int col = table[0].size();
    vector<int> colwidth(col);
    for (int i = 0; i < col; i++) {
        colwidth[i] = 0;
        for (int j = 0; j < row; j++) {
            int len = calcLength(table[j][i]);
            if (len > colwidth[i]) {
                colwidth[i] = len;
            }
        }
        colwidth[i] += 2;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << table[i][j];
            int len = calcLength(table[i][j]);
            for (int k = 0; k < colwidth[j] - len; k++) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int ShowTable::countChinese(string str){
    int chinese = 0;
    for (int i = 0; i < str.size(); )
    {
        if ((str[i] & 0xF0) == 0xE0){
            i+=3;
            chinese++;
        }
        else i++;
    }
    return chinese;
}

int ShowTable::calcLength(string str){
    int length = 0;
    for (int i = 0; i < str.size(); )
    {
        if ((str[i] & 0xF0) == 0xE0){
            i+=3;
            length += 2;
        }
        else{
            i++;
            length++;
        }
    }
    return length;
}




