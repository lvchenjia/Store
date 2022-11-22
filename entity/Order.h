#ifndef ORDER_H
#define ORDER_H

#include "Time.h"
#include "Utility.h"
#include <string>
#include <vector>
using namespace std;

enum OrderStatus {
    UNPAID, PAID
};

class Order {
public:
    Order() = default;

    Order(const string &orderId, const string &customerId, const string &note, const Time &createTime, double total,
          OrderStatus status);

    const string &getOrderId() const;

    void setOrderId(const string &orderId);

    const string &getCustomerId() const;

    void setCustomerId(const string &customerId);

    const string &getNote() const;

    void setNote(const string &note);

    const Time &getCreateTime() const;

    void setCreateTime(const Time &createTime);

    double getTotal() const;

    void setTotal(double total);

    OrderStatus getStatus() const;

    void setStatus(OrderStatus status);

    vector<string> toVector() const;

    static vector<string> fields();

private:
    string orderId;
    string customerId;
    string note;
    Time createTime;
    double total;
    OrderStatus status;
};

#endif


//CREATE TABLE `orders` (
//  `orderid` varchar(255) NOT NULL,
//  `customerid` varchar(255) NOT NULL,
//  `note` varchar(255) DEFAULT NULL,
//  `createtime` datetime NOT NULL,
//  `total` double NOT NULL,
//  `status` int NOT NULL,
//  PRIMARY KEY (`orderid`)
//)
