//
// Created by Horse on 2022/11/22.
//

#include "OrderController.h"

OrderController::OrderController() {
    database = new Database();
}

OrderController::~OrderController() {
    delete database;
}

StatusCode OrderController::addOrder(const Order &order) {
    try{
        QueryResult result = database->select("select * from orders where orderid = '" + order.getOrderId() + "'");
        if (!result.rows.empty()) {
            return {1, "订单号已存在"};
        }
        database->update("insert into orders values ('" + order.getOrderId() + "', '" + order.getCustomerId() + "', '" + order.getNote() + "', '" + order.getCreateTime().toString() + "', " + to_string(order.getTotal()) + ", " + to_string(order.getStatus()) + ")");
        return {0, "添加成功"};
    }
    catch (DbException e){
        return {2, "数据库错误:"+e.getMsg()};
    }
}

StatusCode OrderController::deleteOrder(const string &id) {
    try{
        QueryResult result = database->select("select * from orders where orderid = '" + id + "'");
        if (result.rows.empty()) {
            return {1, "订单号不存在"};
        }
        database->update("delete from orders where orderid = '" + id + "'");
        return {0, "删除成功"};
    }
    catch (DbException e){
        return {2, "数据库错误:"+e.getMsg()};
    }
}

StatusCode OrderController::updateOrder(const Order &order, const string &originalId) {
    try{
        QueryResult result = database->select("select * from orders where orderid = '" + originalId + "'");
        if (result.rows.empty()) {
            return {1, "订单号不存在"};
        }
        database->update("update orders set orderid = '" + order.getOrderId() + "', customerid = '" + order.getCustomerId() + "', note = '" + order.getNote() + "', createtime = '" + order.getCreateTime().toString() + "', total = " + to_string(order.getTotal()) + ", status = " + to_string(order.getStatus()) + " where orderid = '" + originalId + "'");
        return {0, "修改成功"};
    }
    catch (DbException e){
        return {2, "数据库错误:"+e.getMsg()};
    }
}

vector<Order> OrderController::getAllOrders() {
    vector<Order> orders;
    try{
        QueryResult result = database->select("select * from orders");
        for (auto row : result.rows) {
            orders.push_back(Order(row[0], row[1], row[2], Time(row[3]), stod(row[4]), (OrderStatus)stoi(row[5])));
        }
    }
    catch (DbException e){
        return orders;
    }
    return orders;
}

Order OrderController::getOrderById(const string &customerId) {
    try{
        QueryResult result = database->select("select * from orders where orderid = '" + customerId + "'");
        if (result.rows.empty()) {
            return Order();
        }
        return Order(result.rows[0][0], result.rows[0][1], result.rows[0][2], Time(result.rows[0][3]), stod(result.rows[0][4]), (OrderStatus)stoi(result.rows[0][5]));
    }
    catch (DbException e){
        return Order();
    }
}

StatusCode OrderController::addOrderItem(const OrderItem &orderItem) {
    try{
        QueryResult result = database->select("select * from orderitems where orderitemid = '" + orderItem.getOrderItemId() + "'");
        if (!result.rows.empty()) {
            return {1, "订单项号已存在"};
        }
        database->update("insert into orderitem values ('" + orderItem.getOrderItemId() + "', '" + orderItem.getOrderId() + "', '" + orderItem.getCommodityId() + "', '" + orderItem.getCommodityName() + "', " + to_string(orderItem.getQuantity()) + ", " + to_string(orderItem.getOriginalPrice()) + ", " + to_string(orderItem.getDiscount()) + ", " + to_string(orderItem.getDiscountPrice()) + ", " + to_string(orderItem.getTotal()) + ")");
        return {0, "添加成功"};
    }
    catch (DbException e){
        return {2, "数据库错误:"+e.getMsg()};
    }
}

StatusCode OrderController::deleteOrderItem(const string &id) {
    try{
        QueryResult result = database->select("select * from orderitems where orderitemid = '" + id + "'");
        if (result.rows.empty()) {
            return {1, "订单项号不存在"};
        }
        database->update("delete from orderitem where orderitemid = '" + id + "'");
        return {0, "删除成功"};
    }
    catch (DbException e){
        return {2, "数据库错误:"+e.getMsg()};
    }
}

StatusCode OrderController::updateOrderItem(const OrderItem &orderItem, const string &originalId) {
    try{
        QueryResult result = database->select("select * from orderitems where orderitemid = '" + originalId + "'");
        if (result.rows.empty()) {
            return {1, "订单项号不存在"};
        }
        database->update("update orderitem set orderitemid = '" + orderItem.getOrderItemId() + "', orderid = '" + orderItem.getOrderId() + "', commodityid = '" + orderItem.getCommodityId() + "', commodityname = '" + orderItem.getCommodityName() + "', quantity = " + to_string(orderItem.getQuantity()) + ", originalprice = " + to_string(orderItem.getOriginalPrice()) + ", discount = " + to_string(orderItem.getDiscount()) + ", discountprice = " + to_string(orderItem.getDiscountPrice()) + ", total = " + to_string(orderItem.getTotal()) + " where orderitemid = '" + originalId + "'");
        return {0, "修改成功"};
    }
    catch (DbException e){
        return {2, "数据库错误:"+e.getMsg()};
    }
}

vector<OrderItem> OrderController::getAllOrderItems() {
    vector<OrderItem> orderItems;
    try{
        QueryResult result = database->select("select * from orderitems");
        for (auto row : result.rows) {
            orderItems.push_back(OrderItem(row[0], row[1], row[2], row[3], stoi(row[4]), stod(row[5]), stod(row[6]), stod(row[7]), stod(row[8])));
        }
    }
    catch (DbException e){
        return orderItems;
    }
    return orderItems;
}

vector<OrderItem> OrderController::getOrderItemsByOrderId(const string &orderId) {
    vector<OrderItem> orderItems;
    try{
        QueryResult result = database->select("select * from orderitems where orderid = '" + orderId + "'");
        for (auto row : result.rows) {
            orderItems.push_back(OrderItem(row[0], row[1], row[2], row[3], stoi(row[4]), stod(row[5]), stod(row[6]), stod(row[7]), stod(row[8])));
        }
    }
    catch (DbException e){
        return orderItems;
    }
    return orderItems;
}

vector<OrderItem> OrderController::getOrderItemsByCommodityId(const string &commodityId) {
    vector<OrderItem> orderItems;
    try{
        QueryResult result = database->select("select * from orderitems where commodityid = '" + commodityId + "'");
        for (auto row : result.rows) {
            orderItems.push_back(OrderItem(row[0], row[1], row[2], row[3], stoi(row[4]), stod(row[5]), stod(row[6]), stod(row[7]), stod(row[8])));
        }
    }
    catch (DbException e){
        return orderItems;
    }
    return orderItems;
}