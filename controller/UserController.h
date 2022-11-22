//
// Created by Horse on 2022/11/22.
//

#ifndef STORE_USERCONTROLLER_H
#define STORE_USERCONTROLLER_H

#include "../dao/Database.h"
#include "../entity/User.h"
#include "StatusCode.h"
using namespace std;


class UserController {
public:
    UserController();
    ~UserController();
    StatusCode login(const string &username, const string &password);
private:
    Database *database;
};


#endif //STORE_USERCONTROLLER_H
