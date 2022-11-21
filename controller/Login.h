#ifndef LOGIN_H
#define LOGIN_H

#include "../dao/Database.h"
#include "../entity/User.h"
#include <string>
#include <vector>
#include <iostream>

class Login {
private:
    Database *database;
    User *curUser;
public:
    Login();
    enum LoginStatus {
        SUCCESS, USERNAME_ERROR, PASSWORD_ERROR, DATABASE_ERROR
    };
    LoginStatus login(const string &username, const string &password);
    User *getCurUserInfo() const;
};

#endif
