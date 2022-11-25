#include "Commodity.h"

Commodity::Commodity() {
    id = "";
    name = "";
    price = 0;
    stock = 0;
    description = "";
}

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

string Commodity::getTypeString() const {
    switch (type) {
        case FOOD:
            return "食品";
        case DRINKS:
            return "饮料";
        case CLOTHES:
            return "服装";
        case ELECTRONICS:
            return "电子产品";
        case HARDWARE:
            return "五金";
        case OTHER:
            return "其他";
    }
    return "";
}

string Commodity::getCommodityTypeString(int type) {
    switch (type) {
        case FOOD:
            return "食品";
        case DRINKS:
            return "饮料";
        case CLOTHES:
            return "服装";
        case ELECTRONICS:
            return "电子产品";
        case HARDWARE:
            return "五金";
        case OTHER:
            return "其他";
    }
    return "";
}


vector<string> Commodity::toVector() const {
    vector<string> v;
    v.push_back(id);
    v.push_back(name);
    v.push_back(description);
    v.push_back(Utility::doubleToString(price));
    v.push_back(to_string(stock));
    v.push_back(getTypeString());
    v.push_back(isImported_ ? "是" : "否");
    return v;
}

vector<string> Commodity::fields() {
    return {"商品编号", "商品名称", "商品描述", "商品价格", "商品库存", "商品类型", "是否进口"};
}