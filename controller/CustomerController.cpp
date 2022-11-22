//
// Created by Horse on 2022/11/22.
//

#include "CustomerController.h"


CustomerController::CustomerController() {
    this->database = new Database();
}

CustomerController::~CustomerController() {
    delete this->database;
}

StatusCode CustomerController::addCustomer(const Customer &customer) {
    try{
        QueryResult result = database->select("select username from users where username = '" + customer.getUsername() + "'");
        if(!result.rows.empty()) {
            return StatusCode(1, "用户名已存在");
        }
        database->insert("insert into users(username, password, identity) values('" + customer.getUsername() + "', '" + customer.getPassword() + "', 1)");
        database->insert("insert into customers(username, nickname, address, phone) values('" + customer.getUsername() + "', '" + customer.getNickname() + "', '" + customer.getAddress() + "', '" + customer.getPhone() + "')");
    }
    catch (DbException e){
        return StatusCode(2, "数据库错误:"+e.getMsg());
    }
    return StatusCode(0, "添加成功");
}

StatusCode CustomerController::deleteCustomer(const string &username) {
    try{
        QueryResult result = database->select("select username from users where username = '" + username + "'");
        if(result.rows.empty()) {
            return StatusCode(1, "用户名不存在");
        }
        database->deleteRow("delete from users where username = '" + username + "'");
        database->deleteRow("delete from customers where username = '" + username + "'");
    }
    catch (DbException e){
        return StatusCode(2, "数据库错误:"+e.getMsg());
    }
    return StatusCode(0, "删除成功");
}

StatusCode CustomerController::updateCustomer(const Customer &customer, const string &originalUsername) {
    try{
        QueryResult result = database->select("select username from users where username = '" + originalUsername + "'");
        if(result.rows.empty()) {
            return StatusCode(1, "原用户名不存在");
        }
        database->update("update users set username = '" + customer.getUsername() + "', password = '" + customer.getPassword() + "' where username = '" + originalUsername + "'");
        database->update("update customers set username = '" + customer.getUsername() + "', nickname = '" + customer.getNickname() + "', address = '" + customer.getAddress() + "', phone = '" + customer.getPhone() + "' where username = '" + originalUsername + "'");
    }
    catch (DbException e){
        return StatusCode(2, "数据库错误:"+e.getMsg());
    }
    return StatusCode(0, "修改成功");
}

vector<Customer> CustomerController::getAllCustomers() {
    vector<Customer> customers;
    QueryResult result = database->select("select users.username, password, nickname, address, phone from users,customers where users.username = customers.username and identity = 1");
    for(auto row : result.rows) {
        customers.emplace_back(Customer(row[0], row[1], row[2], row[3], row[4]));
    }
    return customers;
}

Customer CustomerController::getCustomerByUsername(const string &username) {
    QueryResult result = database->select("select users.username, password, nickname, address, phone from users,customers where users.username = customers.username and identity = 1 and users.username = '" + username + "'");
    if(result.rows.empty()) {
        return Customer();
    }
    return Customer(result.rows[0][0], result.rows[0][1], result.rows[0][2], result.rows[0][3], result.rows[0][4]);
}