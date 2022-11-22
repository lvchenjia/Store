//
// Created by Horse on 2022/11/20.
//

#include "RegisterPage.h"

void RegisterPage::show() {
    cout << "==============================" << endl;
    cout << "1.注册管理员" << endl;
    cout << "2.注册顾客" << endl;
    cout << "3.返回" << endl;
    cout << "==============================" << endl;
    cout << "请输入选项：";
    int option;
    cin >> option;
    switch (option) {
        case 1:
            registerAdmin();
            break;
        case 2:
            registerCustomer();
            break;
        case 3:
            return;
        default:
            cout << "输入错误，请重新输入" << endl;
            show();
    }
}

void RegisterPage::registerAdmin() {
    string username;
    string password;
    cout << "请输入用户名：";
    cin >> username;
    cout << "请输入密码：";
    cin >> password;
    AdminController adminController;
    Administrator administrator(username, password);
    StatusCode statusCode = adminController.addAdmin(administrator);
    if(statusCode.isSuccess()){
        cout << "注册成功" << endl;
    }else{
        cout << "注册失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void RegisterPage::registerCustomer() {
    string username;
    string password;
    string nickname;
    string phone;
    string address;
    cout << "请输入用户名：";
    cin >> username;
    cout << "请输入密码：";
    cin >> password;
    cout << "请输入昵称：";
    cin >> nickname;
    cout << "请输入电话：";
    cin >> phone;
    cout << "请输入地址：";
    cin >> address;
    CustomerController customerController;
    Customer customer(username, password, nickname, phone, address);
    StatusCode statusCode = customerController.addCustomer(customer);
    if(statusCode.isSuccess()){
        cout << "注册成功" << endl;
    }else{
        cout << "注册失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}
