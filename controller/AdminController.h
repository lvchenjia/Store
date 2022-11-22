//
// Created by Horse on 2022/11/21.
//

#ifndef STORE_ADMINCONTROLLER_H
#define STORE_ADMINCONTROLLER_H

#include "../dao/Database.h"
#include "../entity/Administrator.h"
#include "StatusCode.h"

#include <string>
#include <vector>
using namespace std;

class AdminController {
private:
    Database *database;
public:
    AdminController();
    ~AdminController();

    StatusCode addAdmin(const Administrator &admin);
    StatusCode deleteAdmin(const string &username);
    StatusCode updateAdmin(const Administrator &admin, const string &originalUsername);
    vector<Administrator> getAllAdmins();
};


#endif //STORE_ADMINCONTROLLER_H
