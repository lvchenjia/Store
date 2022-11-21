#ifndef COMMODITYINORDER_H
#define COMMODITYINORDER_H

#include <string>
using namespace std;

class CommodityInOrder {
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
