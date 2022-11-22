//
// Created by Horse on 2022/11/21.
//

#ifndef STORE_ADMIN_H
#define STORE_ADMIN_H

#include "../dao/Database.h"
#include "../entity/Administrator.h"
#include "../entity/Customer.h"
#include "../entity/Commodity.h"
#include "StatusCode.h"
#include "../entity/Order.h"

#include <string>
#include <vector>
using namespace std;

class Admin {
private:
    Database *database;
    Administrator *currentAdmin;
public:
    Admin(Administrator *currentAdmin);

    //用户管理
    StatusCode addAdmin(const Administrator &admin);
    StatusCode deleteAdmin(const string &username);
    StatusCode updateAdmin(const Administrator &admin, const string &originalUsername);
    vector<Administrator> getAllAdmins();

    StatusCode addCustomer(const Customer &customer);
    StatusCode deleteCustomer(const string &username);
    StatusCode updateCustomer(const Customer &customer, const string &originalUsername);
    vector<Customer> getAllCustomers();

    Administrator getCurrentAdmin();

    //商品管理
    StatusCode addCommodity(const Commodity &commodity);
    StatusCode deleteCommodity(const string &id);
    StatusCode updateCommodity(const Commodity &commodity, const string &originalId);
    vector<Commodity> getAllCommodities();
    Commodity getCommodityById(const string &id);

//    //订单管理
//    StatusCode addOrder(const Order &order);
//    StatusCode deleteOrder(const string &id);
//    StatusCode updateOrder(const Order &order, const string &originalId);
//    vector<Order> getAllOrders();
//
//    //统计
//    int getCustomerCount();
//    int getAdminCount();
//    int getCommodityCount();
//    int getOrderCount();
//
//    //销售额
//    double getSales();
//
//    //销售排行
//    vector<Commodity> getSalesRanking();


};


#endif //STORE_ADMIN_H
