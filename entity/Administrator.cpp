#include <vector>
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

vector<string> Administrator::toVector() const {
    vector<string> result;
    result.push_back(username);
    result.push_back(password);
    return result;
}

vector<string> Administrator::fields() {
    vector<string> result;
    result.push_back("username");
    result.push_back("password");
    return result;
}

