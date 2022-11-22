//
// Created by Horse on 2022/11/20.
//

#ifndef STORE_LOGINPAGE_H
#define STORE_LOGINPAGE_H

#include <iostream>
#include "../controller/UserController.h"
#include "RegisterPage.h"
using namespace std;

class LoginPage {
public:
    LoginPage();
    void show();
private:
    void login();
    void registerUser();
};


#endif //STORE_LOGINPAGE_H
