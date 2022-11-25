//
// Created by Horse on 2022/11/25.
//

#include "CustomerPage.h"

CustomerPage::CustomerPage(Customer *customer) {
    currentCustomer = customer;
    customerController = new CustomerController();
    commodityController = new CommodityController();
    orderController = new OrderController();
}

CustomerPage::~CustomerPage() {
    delete currentCustomer;
    delete customerController;
    delete commodityController;
    delete orderController;
}

void CustomerPage::show() {
    showCustomerMenu();
}

void CustomerPage::showCustomerMenu() {
    while (true) {
        cout << "欢迎您，" << currentCustomer->getNickname() << endl;
        cout << "1. 查看个人信息" << endl;
        cout << "2. 修改个人信息" << endl;
        cout << "3. 查看订单详情" << endl;
        cout << "4. 添加订单" << endl;
        cout << "5. 删除订单" << endl;
        cout << "6. 支付订单" << endl;
        cout << "7. 退出" << endl;
        cout << "请输入您的选择：";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                showCustomerInfo();
                break;
            case 2:
                updateCustomerInfo();
                break;
            case 3:
                showOrderDetail();
                break;
            case 4:
                addOrder();
                break;
            case 5:
                deleteOrder();
                break;
            case 6:
                payOrder();
                break;
            case 7:
                return;
            default:
                cout << "输入错误，请重新输入" << endl;
                break;
        }
    }
}

void CustomerPage::showCustomerInfo() {
    cout << "您的个人信息如下：" << endl;
    vector<vector<string>> info;
    info.push_back(currentCustomer->fields());
    info.push_back(currentCustomer->toVector());
    ShowTable::printTable(info);
}

void CustomerPage::updateCustomerInfo() {
    cout << "请输入您的新昵称：";
    string nickname;
    cin >> nickname;
    cout << "请输入您的新密码：";
    string password;
    cin >> password;
    cout << "请输入您的新电话号码：";
    string phone;
    cin >> phone;
    cout << "请输入您的新地址：";
    string address;
    cin >> address;
    currentCustomer->setNickname(nickname);
    currentCustomer->setPassword(password);
    currentCustomer->setPhone(phone);
    currentCustomer->setAddress(address);
    StatusCode statusCode = customerController->updateCustomer(*currentCustomer, currentCustomer->getUsername());
    if (statusCode.isSuccess()) {
        cout << "修改成功" << endl;
    } else {
        cout << "修改失败" << endl;
        cout<<statusCode.getMessage()<<endl;
    }
}

void CustomerPage::showAllOrders() {
    vector<Order> orders = orderController->getOrdersByCustomerName(currentCustomer->getUsername());
    if (orders.empty()) {
        cout << "您还没有订单" << endl;
        return;
    }
    vector<vector<string>> info;
    info.push_back(Order::fields());
    for (Order order : orders) {
        info.push_back(order.toVector());
    }
    ShowTable::printTable(info);

}

void CustomerPage::showOrderDetail() {
    showAllOrders();
    while (true){
        cout<<"请输入您要查看的订单编号(输入c结束)：";
        string orderId;
        cin>>orderId;
        if(orderId=="c"){
            break;
        }
        Order order = orderController->getOrderById(orderId);
        if(order.getOrderId().empty()){
            cout<<"订单不存在，请重新输入"<<endl;
        }else{
            vector<vector<string>> info;
            info.push_back(Order::fields());
            info.push_back(order.toVector());
            ShowTable::printTable(info);
            vector<vector<string>> items;
            items.push_back(OrderItem::fields());
            for(OrderItem orderItem:orderController->getAllOrderItemsByOrderId(orderId)){
                items.push_back(orderItem.toVector());
            }
            ShowTable::printTable(items);
        }
    }
}

void CustomerPage::addOrder() {
    Order order;
    order.setOrderId(to_string(stoi(orderController->getLastOrderId()) + 1));
    order.setCreateTime(Time());
    order.setCustomerId(currentCustomer->getUsername());
    string note;
    cout<<"请输入备注：";
    cin>>note;
    order.setNote(note);
    order.setStatus(OrderStatus::UNPAID);
    order.setTotal(0);
    StatusCode statusCode = orderController->addOrder(order);
    if (statusCode.isSuccess()) {
        cout << "订单添加成功" << endl;
    } else {
        cout << "添加失败" << endl;
        cout<<statusCode.getMessage()<<endl;
        return;
    }

    vector<vector<string>> commoditiesTable;
    commoditiesTable.push_back({"id", "name", "description", "price", "stock", "type"});
    vector<vector<string>> commoditiesInfo = commodityController->getAllCommoditiesInfoForCustomer();
    for (vector<string> commodityInfo : commoditiesInfo) {
        commoditiesTable.push_back(commodityInfo);
    }
    ShowTable::printTable(commoditiesTable);

    while(true){
        cout << "请输入您要购买的商品id：";
        string commodityId;
        cin >> commodityId;
        Commodity commodity = commodityController->getCommodityById(commodityId);
        if (commodity.getId() == "") {
            cout << "商品id不存在，请重新输入" << endl;
            continue;
        }
        cout << "请输入您要购买的商品数量：";
        int commodityCount;
        cin >> commodityCount;
        if (commodityCount <= 0) {
            cout << "商品数量必须大于0，请重新输入" << endl;
            continue;
        }
        if (commodityCount > commodity.getStock()) {
            cout << "商品库存不足!" << endl;
            continue;
        }
        OrderItem orderItem;
        orderItem.setOrderItemId(to_string(stoi(orderController->getLastOrderItemId()) + 1));
        orderItem.setCommodityId(commodityId);
        orderItem.setCommodityName(commodity.getName());
        orderItem.setOrderId(order.getOrderId());
        orderItem.setQuantity(commodityCount);
        orderItem.setOriginalPrice(commodity.getPrice());
        orderItem.setDiscount(1);
        orderItem.setTotal(commodity.getPrice() * commodityCount);
        StatusCode statusCode = orderController->addOrderItem(orderItem);
        if (statusCode.isSuccess()) {
            cout << "购买成功" << endl;
        } else {
            cout << "添加失败" << endl;
            cout<<statusCode.getMessage()<<endl;
            return;
        }
        cout << "是否继续添加商品？(y/n)";
        string choice;
        cin >> choice;
        if (choice == "n") {
            break;
        }
    }
}

void CustomerPage::deleteOrder() {
    showAllOrders();
    cout << "请输入您要删除的订单id：";
    string orderId;
    cin >> orderId;
    StatusCode statusCode = orderController->deleteOrder(orderId);
    if (statusCode.isSuccess()) {
        cout << "删除成功" << endl;
    } else {
        cout << "删除失败" << endl;
        cout<<statusCode.getMessage()<<endl;
    }
}

void CustomerPage::payOrder() {
    showAllOrders();
    cout << "请输入您要支付的订单id：";
    string orderId;
    cin >> orderId;
    double total = orderController->getTotalPriceByOrderId(orderId);
    cout << "您需要支付" << total << "元" << endl;
    cout<<"确认支付？(y/n)";
    string choice;
    cin>>choice;
    if(choice=="y"){
        StatusCode statusCode = orderController->payOrder(orderId);
        if (statusCode.isSuccess()) {
            cout << "支付成功" << endl;
        } else {
            cout << "支付失败" << endl;
            cout<<statusCode.getMessage()<<endl;
        }
    }
}
