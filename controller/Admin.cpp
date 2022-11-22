//
// Created by Horse on 2022/11/21.
//

#include "Admin.h"

Admin::Admin(Administrator *currentAdmin) {
    database = new Database();
    this->currentAdmin = currentAdmin;
}

StatusCode Admin::addAdmin(const Administrator &admin) {
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

StatusCode Admin::deleteAdmin(const string &username) {
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

StatusCode Admin::updateAdmin(const Administrator &admin, const string &originalUsername) {
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

vector<Administrator> Admin::getAllAdmins() {
    vector<Administrator> admins;
    QueryResult result = database->select("select username, password from users where identity = 0");
    for(auto row : result.rows) {
        admins.emplace_back(Administrator(row[0], row[1]));
    }
    return admins;
}

Administrator Admin::getCurrentAdmin() {
    return *currentAdmin;
}

StatusCode Admin::addCustomer(const Customer &customer) {
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

StatusCode Admin::deleteCustomer(const string &username) {
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

StatusCode Admin::updateCustomer(const Customer &customer, const string &originalUsername) {
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

vector<Customer> Admin::getAllCustomers() {
    vector<Customer> customers;
    QueryResult result = database->select("select users.username, password, nickname, address, phone from users,customers where users.username = customers.username and identity = 1");
    for(auto row : result.rows) {
        customers.emplace_back(Customer(row[0], row[1], row[2], row[3], row[4]));
    }
    return customers;
}

//CREATE TABLE `commodities` (
//`id` varchar(255) DEFAULT NULL COMMENT '商品编号',
//`name` varchar(255) DEFAULT NULL COMMENT '商品名',
//`description` varchar(255) DEFAULT NULL COMMENT '商品描述',
//`price` decimal(10,2) DEFAULT NULL COMMENT '商品价格',
//`stock` int(64) DEFAULT NULL COMMENT '库存量',
//`type` tinyint(255) DEFAULT NULL COMMENT '商品类型',
//`isimported` int(8) DEFAULT NULL COMMENT '是否为进口'
//) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;

StatusCode Admin::addCommodity(const Commodity &commodity) {
    try{
        QueryResult result = database->select("select id from commodities where id = '" + commodity.getId() + "'");
        if(!result.rows.empty()) {
            return StatusCode(1, "商品编号已存在");
        }
        database->insert("insert into commodities(id, name, description, price, stock, type, isimported) values('" + commodity.getId() + "', '" + commodity.getName() + "', '" + commodity.getDescription() + "', " + to_string(commodity.getPrice()) + ", " + to_string(commodity.getStock()) + ", " + to_string(commodity.getType()) + ", " + to_string(commodity.isImported()) + ")");
    }
    catch (DbException e){
        return StatusCode(2, "数据库错误:"+e.getMsg());
    }
    return StatusCode(0, "添加成功");
}

StatusCode Admin::deleteCommodity(const string &id) {
    try{
        QueryResult result = database->select("select id from commodities where id = '" + id + "'");
        if(result.rows.empty()) {
            return StatusCode(1, "商品编号不存在");
        }
        database->deleteRow("delete from commodities where id = '" + id + "'");
    }
    catch (DbException e){
        return StatusCode(2, "数据库错误:"+e.getMsg());
    }
    return StatusCode(0, "删除成功");
}

StatusCode Admin::updateCommodity(const Commodity &commodity, const string &originalId) {
    try{
        QueryResult result = database->select("select id from commodities where id = '" + originalId + "'");
        if(result.rows.empty()) {
            return StatusCode(1, "原商品编号不存在");
        }
        database->update("update commodities set id = '" + commodity.getId() + "', name = '" + commodity.getName() + "', description = '" + commodity.getDescription() + "', price = " + to_string(commodity.getPrice()) + ", stock = " + to_string(commodity.getStock()) + ", type = " + to_string(commodity.getType()) + ", isimported = " + to_string(commodity.isImported()) + " where id = '" + originalId + "'");
    }
    catch (DbException e){
        return StatusCode(2, "数据库错误:"+e.getMsg());
    }
    return StatusCode(0, "修改成功");
}

vector<Commodity> Admin::getAllCommodities() {
    vector<Commodity> commodities;
    QueryResult result = database->select("select id, name, description, price, stock, type, isimported from commodities");
    for(auto row : result.rows) {
        commodities.emplace_back(Commodity(row[0], row[1], row[2], stod(row[3]), stoi(row[4]), (CommodityType)stoi(row[5]), stoi(row[6])));
    }
    return commodities;
}

Commodity Admin::getCommodityById(const std::string &id) {
    QueryResult result = database->select("select id, name, description, price, stock, type, isimported from commodities where id = '" + id + "'");
    if(result.rows.empty()) {
        return Commodity();
    }
    auto row = result.rows[0];
    return Commodity(row[0], row[1], row[2], stod(row[3]), stoi(row[4]), (CommodityType)stoi(row[5]), stoi(row[6]));
}

//CREATE TABLE `orders` (
//`id` varchar(255) DEFAULT NULL COMMENT '订单编号',
//`username` varchar(255) DEFAULT NULL COMMENT '用户名',
//`status` tinyint(255) DEFAULT NULL COMMENT '订单状态',
//`totalprice` decimal(10,2) DEFAULT NULL COMMENT '',
//`time` datetime DEFAULT NULL COMMENT '下单时间'
//) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;

//CREATE TABLE `orderdetails` (
//`orderid` varchar(255) DEFAULT NULL COMMENT '订单编号',
//`commodityid` varchar(255) DEFAULT NULL COMMENT '商品编号',
//`quantity` int(64) DEFAULT NULL COMMENT '数量'
//'discount' decimal(10,2) DEFAULT NULL COMMENT '折扣'
//) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;