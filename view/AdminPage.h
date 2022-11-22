//
// Created by Horse on 2022/11/21.
//

#ifndef STORE_ADMINPAGE_H
#define STORE_ADMINPAGE_H

#include "ShowTable.h"
#include "../controller/AdminController.h"
#include "../controller/CommodityController.h"
#include "../controller/CustomerController.h"
#include "../controller/OrderController.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AdminPage {
public:
    AdminPage(Administrator *admin);
    ~AdminPage();
    void show();
private:
    Administrator *currentAdmin;
    AdminController *adminController;
    CustomerController *customerController;
    CommodityController *commodityController;
    OrderController *orderController;

    void showAdminMenu();

    void showAdminsAdminMenu();
    void showCustomersAdminMenu();
    void showCommoditiesAdminMenu();
    void showOrdersAdminMenu();

    void addAdmin();
    void deleteAdmin();
    void updateAdmin();
    void showAllAdmins();

    void addCustomer();
    void deleteCustomer();
    void updateCustomer();
    void showAllCustomers();

    void addCommodity();
    void deleteCommodity();
    void updateCommodity();
    void showAllCommodities();

    void addOrder();
    void deleteOrder();
    void updateOrder();
    void showAllOrders();


};


#endif //STORE_ADMINPAGE_H
