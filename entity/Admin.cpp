#include "Admin.h"

Admin::Admin(const string &username, const string &password) : username(username),
                                                                                       password(password){}

const string &Admin::getUsername() const {
    return username;
}

void Admin::setUsername(const string &username) {
    Admin::username = username;
}

const string &Admin::getPassword() const {
    return password;
}

void Admin::setPassword(const string &password) {
    Admin::password = password;
}

