//
// Created by Horse on 2022/11/25.
//

#ifndef STORE_CUSTOMERPAGE_H
#define STORE_CUSTOMERPAGE_H

#include "ShowTable.h"
#include "../controller/CommodityController.h"
#include "../controller/CustomerController.h"
#include "../controller/OrderController.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CustomerPage {
public:
    CustomerPage(Customer *customer);
    ~CustomerPage();
    void show();
private:
    Customer *currentCustomer;
    CustomerController *customerController;
    CommodityController *commodityController;
    OrderController *orderController;

    void showCustomerMenu();

    void addOrder();
    void deleteOrder();
    void payOrder();
    void showAllOrders();
    void showOrderDetail();

    void showCustomerInfo();
    void updateCustomerInfo();


};


#endif //STORE_CUSTOMERPAGE_H
