//
// Created by Horse on 2022/11/21.
//

#include "AdminController.h"

AdminController::AdminController() {
    database = new Database();
}

AdminController::~AdminController() {
    delete database;
}

StatusCode AdminController::addAdmin(const Administrator &admin) {
    try{
        QueryResult result = database->select("select username from users where username = '" + admin.getUsername() + "'");
        if(!result.rows.empty()) {
            return StatusCode(1, "用户名已存在");
        }
        database->insert("insert into users(username, password, identity) values('" + admin.getUsername() + "', '" + admin.getPassword() + "', 0)");
    }
    catch (DbException e){
        return StatusCode(2, "数据库错误:"+e.getMsg());
    }
    return StatusCode(0, "添加成功");
}

StatusCode AdminController::deleteAdmin(const string &username) {
    try{
        QueryResult result = database->select("select username from users where username = '" + username + "'");
        if(result.rows.empty()) {
            return StatusCode(1, "用户名不存在");
        }
        database->deleteRow("delete from users where username = '" + username + "'");
    }
    catch (DbException e){
        return StatusCode(2, "数据库错误:"+e.getMsg());
    }
    return StatusCode(0, "删除成功");
}

StatusCode AdminController::updateAdmin(const Administrator &admin, const string &originalUsername) {
    try{
        QueryResult result = database->select("select username from users where username = '" + originalUsername + "'");
        if(result.rows.empty()) {
            return StatusCode(1, "原用户名不存在");
        }
        database->update("update users set username = '" + admin.getUsername() + "', password = '" + admin.getPassword() + "' where username = '" + originalUsername + "'");
    }
    catch (DbException e){
        return StatusCode(2, "数据库错误:"+e.getMsg());
    }
    return StatusCode(0, "更新成功");
}

vector<Administrator> AdminController::getAllAdmins() {
    vector<Administrator> admins;
    QueryResult result = database->select("select username, password from users where identity = 0");
    for(auto row : result.rows) {
        admins.emplace_back(Administrator(row[0], row[1]));
    }
    return admins;
}
