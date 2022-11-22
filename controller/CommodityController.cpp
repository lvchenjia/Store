//
// Created by Horse on 2022/11/22.
//

#include "CommodityController.h"

CommodityController::CommodityController() {
    database = new Database();
}

CommodityController::~CommodityController() {
    delete database;
}

StatusCode CommodityController::addCommodity(const Commodity &commodity) {
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

StatusCode CommodityController::deleteCommodity(const string &id) {
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

StatusCode CommodityController::updateCommodity(const Commodity &commodity, const string &originalId) {
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

vector<Commodity> CommodityController::getAllCommodities() {
    vector<Commodity> commodities;
    QueryResult result = database->select("select id, name, description, price, stock, type, isimported from commodities");
    for(auto row : result.rows) {
        commodities.emplace_back(Commodity(row[0], row[1], row[2], stod(row[3]), stoi(row[4]), (CommodityType)stoi(row[5]), stoi(row[6])));
    }
    return commodities;
}

Commodity CommodityController::getCommodityById(const std::string &id) {
    QueryResult result = database->select("select id, name, description, price, stock, type, isimported from commodities where id = '" + id + "'");
    if(result.rows.empty()) {
        return Commodity();
    }
    auto row = result.rows[0];
    return Commodity(row[0], row[1], row[2], stod(row[3]), stoi(row[4]), (CommodityType)stoi(row[5]), stoi(row[6]));
}
