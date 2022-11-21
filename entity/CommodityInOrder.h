#ifndef COMMODITYINORDER_H
#define COMMODITYINORDER_H

#include <string>
using namespace std;

class CommodityInOrder {
public:
    CommodityInOrder(const string &commodityId, const string &commodityName, int quantity, double originalPrice,
                     double discount, double discountPrice, double total);

    const string &getCommodityId() const;

    void setCommodityId(const string &commodityId);

    const string &getCommodityName() const;

    void setCommodityName(const string &commodityName);

    int getQuantity() const;

    void setQuantity(int quantity);

    double getOriginalPrice() const;

    void setOriginalPrice(double originalPrice);

    double getDiscount() const;

    void setDiscount(double discount);

    double getDiscountPrice() const;

    void setDiscountPrice(double discountPrice);

    double getTotal() const;

    void setTotal(double total);

private:
    string commodityId;
    string commodityName;
    int quantity;
    double originalPrice;
    double discount;
    double discountPrice;
    double total;
};

#endif
