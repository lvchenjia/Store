//
// Created by Horse on 2022/11/25.
//

#ifndef STORE_ENCRYPT_H
#define STORE_ENCRYPT_H

#include <string>
#include "AES.h"
using namespace std;

class Encrypt {
public:
    Encrypt();
    ~Encrypt();
    string encrypt(const string &str);
    string decrypt(const string &str);
private:
    AES *aes;
};


#endif //STORE_ENCRYPT_H
