//
// Created by Horse on 2022/11/20.
//

#ifndef STORE_REGISTER_H
#define STORE_REGISTER_H

#include "../dao/Database.h"
#include "../entity/User.h"
#include "../entity/Administrator.h"
#include "../entity/Customer.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Register {
private:
    Database *database;
public:
    Register();
    enum RegisterStatus {
        SUCCESS, USERNAME_EXIST, DATABASE_ERROR
    };
    RegisterStatus registerAdmin(const Administrator &admin);
    RegisterStatus registerCustomer(const Customer &customer);
};


#endif //STORE_REGISTER_H
