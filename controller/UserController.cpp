//
// Created by Horse on 2022/11/22.
//

#include "UserController.h"

UserController::UserController() {
    database = new Database();
}

UserController::~UserController() {
    delete database;
}

StatusCode UserController::login(const string &username, const string &password) {
    try{
        QueryResult result = database->select("select * from user where username = '" + username + "'");
        if (result.rows.empty()) {
            return {1, "用户名不存在"};
        }
        if (result.rows[0][1] != password) {
            return {2, "密码错误"};
        }
        return {0, "登录成功"};
    }
    catch (DbException e){
        return {3, "数据库错误:"+e.getMsg()};
    }
}