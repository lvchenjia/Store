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
public:
    Order(int id, int customerId, const Time &createTime, const vector<CommodityInOrder> &commodities, double total,
          OrderStatus status);

    int getId() const;

    void setId(int id);

    int getCustomerId() const;

    void setCustomerId(int customerId);

    const Time &getCreateTime() const;

    void setCreateTime(const Time &createTime);

    const vector<CommodityInOrder> &getCommodities() const;

    void setCommodities(const vector<CommodityInOrder> &commodities);

    double getTotal() const;

    void setTotal(double total);

    OrderStatus getStatus() const;

    void setStatus(OrderStatus status);

private:
    int id;
    int customerId;
    Time createTime;
    vector<CommodityInOrder> commodities;
    double total;
    OrderStatus status;
};

#endif
