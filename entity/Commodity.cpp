#include "Commodity.h"

Commodity::Commodity(const string &id, const string &name, const string &description, double price, int stock,
                     CommodityType type, bool isImported) : id(id), name(name), description(description), price(price),
                                                            stock(stock), type(type), isImported_(isImported) {}

const string &Commodity::getId() const {
    return id;
}

void Commodity::setId(const string &id) {
    Commodity::id = id;
}

const string &Commodity::getName() const {
    return name;
}

void Commodity::setName(const string &name) {
    Commodity::name = name;
}

const string &Commodity::getDescription() const {
    return description;
}

void Commodity::setDescription(const string &description) {
    Commodity::description = description;
}

double Commodity::getPrice() const {
    return price;
}

void Commodity::setPrice(double price) {
    Commodity::price = price;
}

int Commodity::getStock() const {
    return stock;
}

void Commodity::setStock(int stock) {
    Commodity::stock = stock;
}

CommodityType Commodity::getType() const {
    return type;
}

void Commodity::setType(CommodityType type) {
    Commodity::type = type;
}

bool Commodity::isImported() const {
    return isImported_;
}

void Commodity::setIsImported(bool isImported) {
    isImported_ = isImported;
}
