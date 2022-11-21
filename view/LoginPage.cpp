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
    Login login;
    Login::LoginStatus status = login.login(username, password);
    if (status == Login::LoginStatus::SUCCESS) {
        cout << "登录成功" << endl;
        Administrator *admin;
        Customer *customer;
        if (login.getCurUserInfo()->getIdentity() == 0) {
            admin = new Administrator(login.getCurUserInfo()->getUsername(), login.getCurUserInfo()->getPassword());
            AdminPage adminPage(admin);
            adminPage.show();
        } else {

        }
    } else if (status == Login::LoginStatus::PASSWORD_ERROR) {
        cout << "密码错误" << endl;
    } else if (status == Login::LoginStatus::USERNAME_ERROR) {
        cout << "用户不存在" << endl;
    }
}

void LoginPage::registerUser() {
    RegisterPage registerPage;
    registerPage.show();
}


