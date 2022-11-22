#ifndef ORDER_H
#define ORDER_H

#include "OrderItem.h"
#include "Time.h"

#include <vector>
using namespace std;

enum OrderStatus {
    UNPAID, PAID
};

class Order {
public:
    Order(int orderId, int customerId, const Time &createTime, const vector<OrderItem> &commodities,
          double total, OrderStatus status);

    int getOrderId() const;

    void setOrderId(int orderId);

    int getCustomerId() const;

    void setCustomerId(int customerId);

    const Time &getCreateTime() const;

    void setCreateTime(const Time &createTime);

    const vector<OrderItem> &getCommodities() const;

    void setCommodities(const vector<OrderItem> &commodities);

    double getTotal() const;

    void setTotal(double total);

    OrderStatus getStatus() const;

    void setStatus(OrderStatus status);

    vector<string> toVector() const;

    static vector<string> fields();

private:
    int orderId;
    int customerId;
    Time createTime;
    vector<OrderItem> commodities;
    string orderItemsId;
    double total;
    OrderStatus status;
};

#endif
