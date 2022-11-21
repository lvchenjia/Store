#include "Administrator.h"

Administrator::Administrator(const string &username, const string &password) : username(username),
                                                                               password(password){}

const string &Administrator::getUsername() const {
    return username;
}

void Administrator::setUsername(const string &username) {
    Administrator::username = username;
}

const string &Administrator::getPassword() const {
    return password;
}

void Administrator::setPassword(const string &password) {
    Administrator::password = password;
}

