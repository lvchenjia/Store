#include "OrderItem.h"

OrderItem::OrderItem(const string &commodityId, const string &commodityName, int quantity,
                     double originalPrice, double discount, double discountPrice, double total)
        : commodityId(commodityId), commodityName(commodityName), quantity(quantity), originalPrice(originalPrice),
          discount(discount), discountPrice(discountPrice), total(total) {}

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
