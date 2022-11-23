#ifndef COMMODITYINORDER_H
#define COMMODITYINORDER_H

#include <string>
#include <vector>
#include "Utility.h"
using namespace std;

class OrderItem {
public:
    OrderItem() = default;

    OrderItem(const string &orderItemId, const string &orderId, const string &commodityId, const string &commodityName,
              int quantity, double originalPrice, double discount, double discountPrice, double total);

    vector<string> toVector() const;

    static vector<string> fields();

    const string &getOrderItemId() const;

    void setOrderItemId(const string &orderItemId);

    const string &getOrderId() const;

    void setOrderId(const string &orderId);

    const string &getCommodityId() const;

    void setCommodityId(const string &commodityId);

    const string &getCommodityName() const;

    void setCommodityName(const string &commodityName);

    int getQuantity() const;

    void setQuantity(int quantity);

    double getOriginalPrice() const;

    void setOriginalPrice(double originalPrice);

    double getDiscount() const;

    void setDiscount(double discount);

    double getDiscountPrice() const;

    void setDiscountPrice(double discountPrice);

    double getTotal() const;

    void setTotal(double total);


private:
    string orderItemId;
    string orderId;
    string commodityId;
    string commodityName;
    int quantity;
    double originalPrice;
    double discount;
    double discountPrice;
    double total;
};

#endif

//CREATE TABLE `orderitems` (
//  `orderitemid` varchar(255) NOT NULL,
//  `orderid` varchar(255) NOT NULL,
//  `commodityid` varchar(255) NOT NULL,
//  `commodityname` varchar(255) NOT NULL,
//  `quantity` int NOT NULL,
//  `originalprice` double NOT NULL,
//  `discount` double NOT NULL,
//  `discountprice` double NOT NULL,
//  `total` double NOT NULL,
//  PRIMARY KEY (`orderitemsid`),
//  KEY `orderid` (`orderid`),
//  KEY `commodityid` (`commodityid`),
//  CONSTRAINT `orderitems_ibfk_1` FOREIGN KEY (`orderid`) REFERENCES `orders` (`orderid`),
//  CONSTRAINT `orderitems_ibfk_2` FOREIGN KEY (`commodityid`) REFERENCES `commodities` (`commodityid`)
//) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4
