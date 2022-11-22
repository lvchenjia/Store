#include "OrderItem.h"

OrderItem::OrderItem(const string &orderItemId, const string &orderId, const string &commodityId,
                     const string &commodityName, int quantity, double originalPrice, double discount,
                     double discountPrice, double total) : orderItemId(orderItemId), orderId(orderId),
                                                           commodityId(commodityId), commodityName(commodityName),
                                                           quantity(quantity), originalPrice(originalPrice),
                                                           discount(discount), discountPrice(discountPrice),
                                                           total(total) {}

const string &OrderItem::getOrderItemId() const {
    return orderItemId;
}

void OrderItem::setOrderItemId(const string &orderItemId) {
    OrderItem::orderItemId = orderItemId;
}

const string &OrderItem::getOrderId() const {
    return orderId;
}

void OrderItem::setOrderId(const string &orderId) {
    OrderItem::orderId = orderId;
}

const string &OrderItem::getCommodityId() const {
    return commodityId;
}

void OrderItem::setCommodityId(const string &commodityId) {
    OrderItem::commodityId = commodityId;
}

const string &OrderItem::getCommodityName() const {
    return commodityName;
}

void OrderItem::setCommodityName(const string &commodityName) {
    OrderItem::commodityName = commodityName;
}

int OrderItem::getQuantity() const {
    return quantity;
}

void OrderItem::setQuantity(int quantity) {
    OrderItem::quantity = quantity;
}

double OrderItem::getOriginalPrice() const {
    return originalPrice;
}

void OrderItem::setOriginalPrice(double originalPrice) {
    OrderItem::originalPrice = originalPrice;
}

double OrderItem::getDiscount() const {
    return discount;
}

void OrderItem::setDiscount(double discount) {
    OrderItem::discount = discount;
}

double OrderItem::getDiscountPrice() const {
    return discountPrice;
}

void OrderItem::setDiscountPrice(double discountPrice) {
    OrderItem::discountPrice = discountPrice;
}

double OrderItem::getTotal() const {
    return total;
}

void OrderItem::setTotal(double total) {
    OrderItem::total = total;
}

vector<string> OrderItem::toVector() const {
    vector<string> result;
    result.push_back(orderItemId);
    result.push_back(orderId);
    result.push_back(commodityId);
    result.push_back(commodityName);
    result.push_back(to_string(quantity));
    result.push_back(Utility::doubleToString(originalPrice));
    result.push_back(Utility::doubleToString(discount));
    result.push_back(Utility::doubleToString(discountPrice));
    result.push_back(Utility::doubleToString(total));
    return result;
}

vector<string> OrderItem::fields() {
    vector<string> result = {"orderItemId", "orderId", "commodityId", "commodityName", "quantity", "originalPrice",
                             "discount", "discountPrice", "total"};
    return result;
}