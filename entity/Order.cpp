#include "Order.h"

Order::Order(int id, int customerId, const Time &createTime, const vector<CommodityInOrder> &commodities, double total,
             OrderStatus status) : id(id), customerId(customerId), createTime(createTime), commodities(commodities),
                                   total(total), status(status) {}

int Order::getId() const {
    return id;
}

void Order::setId(int id) {
    Order::id = id;
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

const vector<CommodityInOrder> &Order::getCommodities() const {
    return commodities;
}

void Order::setCommodities(const vector<CommodityInOrder> &commodities) {
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
