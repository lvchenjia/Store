#ifndef ORDER_H
#define ORDER_H

#include "CommodityInOrder.h"
#include "Time.h"

#include <vector>
using namespace std;

enum OrderStatus {
    UNPAID, PAID
};

class Order {
private:
    int id;
    int customerId;
    Time createTime;
    vector<CommodityInOrder> commodities;
    double total;
    OrderStatus status;
};

#endif
