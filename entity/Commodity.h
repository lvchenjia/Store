#ifndef COMMODITY_H
#define COMMODITY_H

#include <string>
using namespace std;

//商品品类 1-食品 2-饮料 3-服装 4-电子产品 5-五金 6-其他
enum CommodityType {
    FOOD, DRINKS ,CLOTHES, ELECTRONICS, HARDWARE, OTHER
};

class Commodity {
public:
    Commodity(const string &id, const string &name, const string &description, double price, int stock,
              CommodityType type, bool isImported);

    const string &getId() const;

    void setId(const string &id);

    const string &getName() const;

    void setName(const string &name);

    const string &getDescription() const;

    void setDescription(const string &description);

    double getPrice() const;

    void setPrice(double price);

    int getStock() const;

    void setStock(int stock);

    CommodityType getType() const;

    void setType(CommodityType type);

    bool isImported() const;

    void setIsImported(bool isImported);

public:

private:
    string id;
    string name;
    string description;
    double price;
    int stock;//库存
    CommodityType type;
    bool isImported_;//是否是进口商品
};


#endif
