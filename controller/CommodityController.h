//
// Created by Horse on 2022/11/22.
//

#ifndef STORE_COMMODITYCONTROLLER_H
#define STORE_COMMODITYCONTROLLER_H

#include "../dao/Database.h"
#include "../entity/Commodity.h"
#include "StatusCode.h"

#include <string>
#include <vector>
using namespace std;

//CREATE TABLE `commodities` (
//`id` varchar(255) DEFAULT NULL COMMENT '商品编号',
//`name` varchar(255) DEFAULT NULL COMMENT '商品名',
//`description` varchar(255) DEFAULT NULL COMMENT '商品描述',
//`price` decimal(10,2) DEFAULT NULL COMMENT '商品价格',
//`stock` int(64) DEFAULT NULL COMMENT '库存量',
//`type` tinyint(255) DEFAULT NULL COMMENT '商品类型',
//`isimported` int(8) DEFAULT NULL COMMENT '是否为进口'
//) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;

class CommodityController {
public:
    CommodityController();
    ~CommodityController();
    StatusCode addCommodity(const Commodity &commodity);
    StatusCode deleteCommodity(const string &id);
    StatusCode updateCommodity(const Commodity &commodity, const string &originalId);
    vector<Commodity> getAllCommodities();
    Commodity getCommodityById(const string &id);
private:
    Database *database;
};


#endif //STORE_COMMODITYCONTROLLER_H
