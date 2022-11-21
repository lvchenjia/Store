//
// Created by Horse on 2022/11/20.
//

#include "Register.h"

Register::Register() {
    database = new Database();
}

Register::RegisterStatus Register::registerAdmin(const Administrator &admin) {
    try{
        cout<<admin.getUsername()<<endl;
        QueryResult result = database->select("select username from users where username = '" + admin.getUsername() + "'");
        if(!result.rows.empty()) {
            return USERNAME_EXIST;
        }

        database->insert("insert into users(username, password, identity) values('" + admin.getUsername() + "', '" + admin.getPassword() + "', 0)");
        return SUCCESS;
    }catch (DbException e){
        cout << e.what() << endl;
        return DATABASE_ERROR;
    }
}

Register::RegisterStatus Register::registerCustomer(const Customer &customer) {
    try{
        QueryResult result = database->select("select username from users where username = '" + customer.getUsername() + "'");
        if(!result.rows.empty()) {
            return USERNAME_EXIST;
        }
        database->insert("insert into users(username, password, identity) values('" + customer.getUsername() + "', '" + customer.getPassword() + "', 1)");
        database->insert("insert into customers(username, nickname, address, phone) values('" + customer.getUsername() + "', '" + customer.getNickname() + "', '" + customer.getAddress() + "', '" + customer.getPhone() + "')");
        return SUCCESS;
    }catch (DbException e){
        cout << e.what() << endl;
        return DATABASE_ERROR;
    }
}