#include "User.h"

User::User(const string &username, const string &password, User::UserIdentity identity) : username(username),
                                                                                          password(password),
                                                                                          identity(identity) {}

User::User(vector<string> &row) {
    username = row[0];
    password = row[1];
    identity = (UserIdentity)stoi(row[2]);
}

const string &User::getUsername() const {
    return username;
}

void User::setUsername(const string &username) {
    User::username = username;
}

const string &User::getPassword() const {
    return password;
}

void User::setPassword(const string &password) {
    User::password = password;
}

User::UserIdentity User::getIdentity() const {
    return identity;
}

void User::setIdentity(User::UserIdentity identity) {
    User::identity = identity;
}
