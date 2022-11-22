//
// Created by Horse on 2022/11/22.
//

#ifndef STORE_CUSTOMERCONTROLLER_H
#define STORE_CUSTOMERCONTROLLER_H

#include "../dao/Database.h"
#include "../entity/Customer.h"
#include "StatusCode.h"

#include <string>
#include <vector>
using namespace std;

class CustomerController {
public:
    CustomerController();
    ~CustomerController();
    StatusCode addCustomer(const Customer &customer);
    StatusCode deleteCustomer(const string &username);
    StatusCode updateCustomer(const Customer &customer, const string &originalUsername);
    vector<Customer> getAllCustomers();
    Customer getCustomerByUsername(const string &username);
private:
    Database *database;
};


#endif //STORE_CUSTOMERCONTROLLER_H
