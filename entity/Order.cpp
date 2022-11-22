#include "Order.h"

Order::Order(int orderId, int customerId, const Time &createTime, const vector<OrderItem> &commodities,
             double total, OrderStatus status) : orderId(orderId), customerId(customerId), createTime(createTime),
                                                 commodities(commodities), total(total), status(status) {}

int Order::getOrderId() const {
    return orderId;
}

void Order::setOrderId(int orderId) {
    Order::orderId = orderId;
}

int Order::getCustomerId() const {
    return customerId;
}

void Order::setCustomerId(int customerId) {
    Order::customerId = customerId;
}

const Time &Order::getCreateTime() const {
    return createTime;
}

void Order::setCreateTime(const Time &createTime) {
    Order::createTime = createTime;
}

const vector<OrderItem> &Order::getCommodities() const {
    return commodities;
}

void Order::setCommodities(const vector<OrderItem> &commodities) {
    Order::commodities = commodities;
}

double Order::getTotal() const {
    return total;
}

void Order::setTotal(double total) {
    Order::total = total;
}

OrderStatus Order::getStatus() const {
    return status;
}

void Order::setStatus(OrderStatus status) {
    Order::status = status;
}
