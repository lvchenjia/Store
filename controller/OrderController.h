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
    StatusCode payOrder(const string &id);
    double getTotalPriceByOrderId(const string &id);
    vector<Order> getAllOrders();
    vector<Order> getOrdersByCustomerName(const string &customerUsername);
    Order getOrderById(const string &id);


    StatusCode addOrderItem(const OrderItem &orderItem);
    StatusCode deleteOrderItem(const string &id);
    StatusCode updateOrderItem(const OrderItem &orderItem, const string &originalId);
    OrderItem getOrderItemById(const string &id);
    vector<OrderItem> getAllOrderItems();
    vector<OrderItem> getAllOrderItemsByOrderId(const string &orderId);
    vector<OrderItem> getOrderItemsByCommodityId(const string &commodityId);
    StatusCode deleteAllOrderItemsByOrderId(const string &orderId);

    //权宜之计 用于获取最后一个订单号 以便生成新的订单号 若是把数据库中id改成int类型要改很多代码
    string getLastOrderId();
    string getLastOrderItemId();
};


#endif //STORE_ORDERCONTROLLER_H
