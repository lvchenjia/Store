//
// Created by Horse on 2022/11/21.
//

#ifndef STORE_ADMINPAGE_H
#define STORE_ADMINPAGE_H

#include "../controller/Admin.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AdminPage {
public:
    AdminPage(Administrator *admin);
    void show();
private:
    Administrator *currentAdmin;
    Admin *adminController;
    void showAdminMenu();

    void showAdminsAdminMenu();
    void showCustomersAdminMenu();
    void showCommoditiesAdminMenu();

    void addAdmin();
    void deleteAdmin();
    void updateAdmin();
    void addCustomer();
    void deleteCustomer();
    void updateCustomer();
    void addCommodity();
    void deleteCommodity();
    void updateCommodity();

    void showCommodities();
};


#endif //STORE_ADMINPAGE_H
