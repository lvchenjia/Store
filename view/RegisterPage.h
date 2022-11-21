#ifndef STORE_REGISTERPAGE_H
#define STORE_REGISTERPAGE_H

#include "../controller/Register.h"
#include <iostream>
#include <string>
using namespace std;

class RegisterPage {
public:
    RegisterPage()= default;
    void show();
private:
    void registerAdmin();
    void registerCustomer();
};


#endif //STORE_REGISTERPAGE_H
