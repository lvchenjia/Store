#include "Order.h"

Order::Order(const string &orderId, const string &customerId, const string &note, const Time &createTime, double total,
             OrderStatus status) : orderId(orderId), customerId(customerId), note(note), createTime(createTime),
                                   total(total), status(status) {}

const string &Order::getOrderId() const {
    return orderId;
}

void Order::setOrderId(const string &orderId) {
    Order::orderId = orderId;
}

const string &Order::getCustomerId() const {
    return customerId;
}

void Order::setCustomerId(const string &customerId) {
    Order::customerId = customerId;
}

const string &Order::getNote() const {
    return note;
}

void Order::setNote(const string &note) {
    Order::note = note;
}

const Time &Order::getCreateTime() const {
    return createTime;
}

void Order::setCreateTime(const Time &createTime) {
    Order::createTime = createTime;
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

vector<string> Order::toVector() const {
    vector<string> result;
    result.push_back(orderId);
    result.push_back(customerId);
    result.push_back(note);
    result.push_back(createTime.toString());
    result.push_back(Utility::doubleToString(total));
    result.push_back(status==UNPAID?"未支付":"已支付");
    return result;
}

vector<string> Order::fields() {
    vector<string> result = {"orderid", "customerid", "note", "createtime", "total", "status"};
    return result;
}
