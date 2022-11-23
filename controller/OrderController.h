//
// Created by Horse on 2022/11/22.
//

#ifndef STORE_ORDERCONTROLLER_H
#define STORE_ORDERCONTROLLER_H

#include "../dao/Database.h"
#include "../entity/Customer.h"
#include "../entity/Commodity.h"
#include "../entity/Order.h"
#include "../entity/OrderItem.h"
#include "StatusCode.h"
#include "CommodityController.h"

#include <string>
#include <vector>
using namespace std;

class OrderController {
private:
    Database *database;
    CommodityController commodityController;
public:
    OrderController();
    ~OrderController();

    StatusCode addOrder(const Order &order);
    StatusCode deleteOrder(const string &id);
    StatusCode updateOrder(const Order &order, const string &originalId);
    vector<Order> getAllOrders();
    Order getOrderById(const string &id);

    StatusCode addOrderItem(const OrderItem &orderItem);
    StatusCode deleteOrderItem(const string &id);
    StatusCode updateOrderItem(const OrderItem &orderItem, const string &originalId);
    OrderItem getOrderItemById(const string &id);
    vector<OrderItem> getAllOrderItems();
    vector<OrderItem> getAllOrderItemsByOrderId(const string &orderId);
    vector<OrderItem> getOrderItemsByCommodityId(const string &commodityId);
    StatusCode deleteAllOrderItemsByOrderId(const string &orderId);
};


#endif //STORE_ORDERCONTROLLER_H
