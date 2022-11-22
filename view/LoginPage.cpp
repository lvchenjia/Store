//
// Created by Horse on 2022/11/20.
//

#include "LoginPage.h"
#include "AdminPage.h"


LoginPage::LoginPage() {

}

void LoginPage::show() {
    while (true){
        cout << "==============================" << endl;
        cout << "1.登录" << endl;
        cout << "2.注册" << endl;
        cout << "3.退出" << endl;
        cout << "==============================" << endl;
        cout << "请输入选项：";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                login();
                break;
            case 2:
                registerUser();
                break;
            case 3:
                exit(0);
            default:
                cout << "输入错误，请重新输入" << endl;
                show();
        }
    }
}

void LoginPage::login() {
    string username;
    string password;
    cout << "请输入用户名：";
    cin >> username;
    cout << "请输入密码：";
    cin >> password;
    UserController userController;
    StatusCode statusCode = userController.login(username, password);
    if (statusCode.isSuccess()) {
        cout << statusCode.getMessage()<< endl;
        if (username == "admin") {
            Administrator *admin = new Administrator(username, password);
            AdminPage adminPage(admin);
            adminPage.show();
        }
        else {
//            Customer *customer = new Customer(username, password);
//            CustomerPage customerPage(customer);
//            customerPage.show();
        }
    }
    else {
        cout << statusCode.getMessage() << endl;
        show();
    }
}

void LoginPage::registerUser() {
    RegisterPage registerPage;
    registerPage.show();
}


