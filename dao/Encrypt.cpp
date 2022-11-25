//
// Created by Horse on 2022/11/25.
//

#include "Encrypt.h"

Encrypt::Encrypt() {
    unsigned char key[] = "1p2w3e4r";
    aes = new AES(key);
}

Encrypt::~Encrypt() {
    delete aes;
}

string Encrypt::encrypt(const string &str) {
    char ch_mingwen[10240];
    char ch_miwen[10240];
    strcpy(ch_mingwen, str.c_str());
    aes->Cipher(ch_mingwen, ch_miwen);
    return string(ch_miwen);
}

string Encrypt::decrypt(const string &str) {
    char ch_mingwen[10240];
    char ch_miwen[10240];
    strcpy(ch_miwen, str.c_str());
    aes->InvCipher(ch_miwen, ch_mingwen);
    return string(ch_mingwen);
}