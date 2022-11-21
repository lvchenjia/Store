#include "CommodityInOrder.h"

CommodityInOrder::CommodityInOrder(const string &commodityId, const string &commodityName, int quantity,
                                   double originalPrice, double discount, double discountPrice, double total)
        : commodityId(commodityId), commodityName(commodityName), quantity(quantity), originalPrice(originalPrice),
          discount(discount), discountPrice(discountPrice), total(total) {}

const string &CommodityInOrder::getCommodityId() const {
    return commodityId;
}

void CommodityInOrder::setCommodityId(const string &commodityId) {
    CommodityInOrder::commodityId = commodityId;
}

const string &CommodityInOrder::getCommodityName() const {
    return commodityName;
}

void CommodityInOrder::setCommodityName(const string &commodityName) {
    CommodityInOrder::commodityName = commodityName;
}

int CommodityInOrder::getQuantity() const {
    return quantity;
}

void CommodityInOrder::setQuantity(int quantity) {
    CommodityInOrder::quantity = quantity;
}

double CommodityInOrder::getOriginalPrice() const {
    return originalPrice;
}

void CommodityInOrder::setOriginalPrice(double originalPrice) {
    CommodityInOrder::originalPrice = originalPrice;
}

double CommodityInOrder::getDiscount() const {
    return discount;
}

void CommodityInOrder::setDiscount(double discount) {
    CommodityInOrder::discount = discount;
}

double CommodityInOrder::getDiscountPrice() const {
    return discountPrice;
}

void CommodityInOrder::setDiscountPrice(double discountPrice) {
    CommodityInOrder::discountPrice = discountPrice;
}

double CommodityInOrder::getTotal() const {
    return total;
}

void CommodityInOrder::setTotal(double total) {
    CommodityInOrder::total = total;
}
