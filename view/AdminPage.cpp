//
// Created by Horse on 2022/11/21.
//

#include "AdminPage.h"

AdminPage::AdminPage(Administrator *admin) {
    currentAdmin = admin;
    adminController = new AdminController();
    customerController = new CustomerController();
    commodityController = new CommodityController();
    orderController = new OrderController();
}

AdminPage::~AdminPage() {
    delete adminController;
    delete customerController;
    delete commodityController;
    delete orderController;
}

void AdminPage::show() {
    cout  << currentAdmin->getUsername() << "管理员，您好！" << endl;
    showAdminMenu();
}

void AdminPage::showAdminMenu() {
    int choice;
    while (true) {
        cout << "1. 管理员管理" << endl;
        cout << "2. 顾客管理" << endl;
        cout << "3. 商品管理" << endl;
        cout << "4. 订单管理" << endl;
        cout << "5. 订单项管理" << endl;
        cout << "6. 退出" << endl;
        cout << "请输入您的选择：";
        cin >> choice;
        switch (choice) {
            case 1:
                showAdminsAdminMenu();
                break;
            case 2:
                showCustomersAdminMenu();
                break;
            case 3:
                showCommoditiesAdminMenu();
                break;
            case 4:
                showOrdersAdminMenu();
                break;
            case 5:
                showOrderItemsAdminMenu();
                break;
            case 6:
                return;
            default:
                cout << "输入错误，请重新输入！" << endl;
                break;
        }
    }
}

void AdminPage::showAdminsAdminMenu() {
    while (true) {
        cout << "==============================" << endl;
        cout << "1.添加管理员" << endl;
        cout << "2.删除管理员" << endl;
        cout << "3.修改管理员" << endl;
        cout << "4.显示所有管理员" << endl;
        cout << "5.返回" << endl;
        cout << "==============================" << endl;
        cout << "请输入选项：";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                addAdmin();
                break;
            case 2:
                deleteAdmin();
                break;
            case 3:
                updateAdmin();
                break;
            case 4:
                showAllAdmins();
                break;
            case 5:
                return;
            default:
                cout << "输入错误，请重新输入" << endl;
        }
    }
}

void AdminPage::showCustomersAdminMenu() {
    while (true) {
        cout << "==============================" << endl;
        cout << "1.添加顾客" << endl;
        cout << "2.删除顾客" << endl;
        cout << "3.修改顾客" << endl;
        cout << "4.显示所有顾客" << endl;
        cout << "5.返回" << endl;
        cout << "==============================" << endl;
        cout << "请输入选项：";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                addCustomer();
                break;
            case 2:
                deleteCustomer();
                break;
            case 3:
                updateCustomer();
                break;
            case 4:
                showAllCustomers();
                break;
            case 5:
                return;
            default:
                cout << "输入错误，请重新输入" << endl;
        }
    }
}

void AdminPage::showCommoditiesAdminMenu() {
    while (true) {
        cout << "==============================" << endl;
        cout << "1.添加商品" << endl;
        cout << "2.删除商品" << endl;
        cout << "3.修改商品" << endl;
        cout << "4.显示商品" << endl;
        cout << "5.返回" << endl;
        cout << "==============================" << endl;
        cout << "请输入选项：";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                addCommodity();
                break;
            case 2:
                deleteCommodity();
                break;
            case 3:
                updateCommodity();
                break;
            case 4:
                showAllCommodities();
                break;
            case 5:
                return;
            default:
                cout << "输入错误，请重新输入" << endl;
        }
    }
}

void AdminPage::showOrdersAdminMenu() {
    while (true) {
        cout << "==============================" << endl;
        cout << "1.添加订单" << endl;
        cout << "2.删除订单" << endl;
        cout << "3.修改订单" << endl;
        cout << "4.显示所有订单" << endl;
        cout << "5.显示订单详情" << endl;
        cout << "6.返回" << endl;
        cout << "==============================" << endl;
        cout << "请输入选项：";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                addOrder();
                break;
            case 2:
                deleteOrder();
                break;
            case 3:
                updateOrder();
                break;
            case 4:
                showAllOrders();
                break;
            case 5:
                showOrderDetails();
                break;
            case 6:
                return;
            default:
                cout << "输入错误，请重新输入" << endl;
        }
    }
}

void AdminPage::showOrderItemsAdminMenu() {
    while (true) {
        cout << "==============================" << endl;
        cout << "1.添加订单项" << endl;
        cout << "2.删除订单项" << endl;
        cout << "3.修改订单项" << endl;
        cout << "4.显示所有订单项" << endl;
        cout << "5.返回" << endl;
        cout << "==============================" << endl;
        cout << "请输入选项：";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                addOrderItem();
                break;
            case 2:
                deleteOrderItem();
                break;
            case 3:
                updateOrderItem();
                break;
            case 4:
                showAllOrderItems();
                break;
            case 5:
                return;
            default:
                cout << "输入错误，请重新输入" << endl;
        }
    }
}

void AdminPage::addAdmin() {
    string name;
    string password;
    cout << "请输入管理员用户名：";
    cin >> name;
    cout << "请输入管理员密码：";
    cin >> password;
    StatusCode statusCode = adminController->addAdmin(Administrator(name, password));
    if (statusCode.isSuccess()) {
        cout << "添加成功" << endl;
    } else {
        cout << "添加失败" << endl;
    }
}

void AdminPage::deleteAdmin() {
    string name;
    cout << "请输入管理员用户名：";
    cin >> name;
    StatusCode statusCode = adminController->deleteAdmin(name);
    if (statusCode.isSuccess()) {
        cout << "删除成功" << endl;
    } else {
        cout << "删除失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void AdminPage::updateAdmin() {
    string originName;
    string name;
    string password;
    cout << "请输入原管理员用户名：";
    cin >> originName;
    cout << "请输入新管理员用户名：";
    cin >> name;
    cout << "请输入新管理员密码：";
    cin >> password;
    StatusCode statusCode = adminController->updateAdmin(Administrator(name, password), originName);
    if (statusCode.isSuccess()) {
        cout << "修改成功" << endl;
    } else {
        cout << "修改失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void AdminPage::showAllAdmins() {
    vector<Administrator> administrators = adminController->getAllAdmins();
    cout << "管理员列表：" << endl;
    vector<vector<string>> table;
    table.push_back(Administrator::fields());
    for (Administrator administrator : administrators) {
        table.push_back(administrator.toVector());
    }
    ShowTable::printTable(table);
}

void AdminPage::addCustomer() {
    string username;
    string password;
    string nickname;
    string address;
    string phone;
    cout << "请输入用户名：";
    cin >> username;
    cout << "请输入密码：";
    cin >> password;
    cout << "请输入昵称：";
    cin >> nickname;
    cout << "请输入地址：";
    cin >> address;
    cout << "请输入电话：";
    cin >> phone;
    StatusCode statusCode = customerController->addCustomer(Customer(username, password, nickname, address, phone));
    if (statusCode.isSuccess()) {
        cout << "添加成功" << endl;
    } else {
        cout << "添加失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void AdminPage::deleteCustomer() {
    string username;
    cout << "请输入用户名：";
    cin >> username;
    StatusCode statusCode = customerController->deleteCustomer(username);
    if (statusCode.isSuccess()) {
        cout << "删除成功" << endl;
    } else {
        cout << "删除失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void AdminPage::updateCustomer() {
    string originUsername;
    string username;
    string password;
    string nickname;
    string address;
    string phone;
    cout << "请输入原用户名：";
    cin >> originUsername;
    cout << "请输入新用户名：";
    cin >> username;
    cout << "请输入新密码：";
    cin >> password;
    cout << "请输入新昵称：";
    cin >> nickname;
    cout << "请输入新地址：";
    cin >> address;
    cout << "请输入新电话：";
    cin >> phone;
    StatusCode statusCode = customerController->updateCustomer(Customer(username, password, nickname, address, phone), originUsername);
    if (statusCode.isSuccess()) {
        cout << "修改成功" << endl;
    } else {
        cout << "修改失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void AdminPage::showAllCustomers() {
    vector<Customer> customers = customerController->getAllCustomers();
    cout << "用户列表：" << endl;
    vector<vector<string>> table;
    table.push_back(Customer::fields());
    for (Customer customer : customers) {
        table.push_back(customer.toVector());
    }
    ShowTable::printTable(table);
}

void AdminPage::addCommodity() {
    string id;
    string name;
    string description;
    double price;
    int stock;
    int type;
    bool isImported;
    cout << "请输入商品编号：";
    cin >> id;
    cout << "请输入商品名称：";
    cin >> name;
    cout << "请输入商品描述：";
    cin >> description;
    cout << "请输入商品价格：";
    cin >> price;
    cout << "请输入商品库存：";
    cin >> stock;
    cout << "商品品类 0-食品 1-饮料 2-服装 3-电子产品 4-五金 5-其他"<< endl;
    cout << "请输入商品类型：";
    cin >> type;
    cout << "请输入商品是否进口：";
    cin >> isImported;
    StatusCode statusCode = commodityController->addCommodity(Commodity(id, name, description, price, stock, (CommodityType) type, isImported));
    if (statusCode.isSuccess()) {
        cout << "添加成功" << endl;
    } else {
        cout << "添加失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void AdminPage::deleteCommodity() {
    string id;
    cout << "请输入商品编号：";
    cin >> id;
    StatusCode statusCode = commodityController->deleteCommodity(id);
    if (statusCode.isSuccess()) {
        cout << "删除成功" << endl;
    } else {
        cout << "删除失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void AdminPage::updateCommodity() {
    string originId;
    string id;
    string name;
    string description;
    double price;
    int stock;
    int type;
    bool isImported;
    cout << "请输入原商品编号：";
    cin >> originId;
    cout<< "原商品信息" << endl;

    Commodity commodity = commodityController->getCommodityById(originId);
    if(commodity.getId().empty()){
        cout << "商品不存在" << endl;
        return;
    }
    ShowTable::printTable({commodity.fields(), commodity.toVector()});

    cout << "请输入新商品编号：";
    cin >> id;
    cout << "请输入新商品名称：";
    cin >> name;
    cout << "请输入新商品描述：";
    cin >> description;
    cout << "请输入新商品价格：";
    cin >> price;
    cout << "请输入新商品库存：";
    cin >> stock;
    cout << "商品品类 0-食品 1-饮料 2-服装 3-电子产品 4-五金 5-其他"<< endl;
    cout << "请输入新商品类型：";
    cin >> type;
    cout << "请输入新商品是否进口：";
    cin >> isImported;
    StatusCode statusCode = commodityController->updateCommodity(Commodity(id, name, description, price, stock, (CommodityType) type, isImported), originId);
    if (statusCode.isSuccess()) {
        cout << "修改成功" << endl;
    } else {
        cout << "修改失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void AdminPage::showAllCommodities() {
    vector<Commodity> commodities = commodityController->getAllCommodities();
    vector<vector<string>> table;
    table.push_back(Commodity::fields());
    for (Commodity commodity : commodities) {
        table.push_back(commodity.toVector());
    }
    ShowTable::printTable(table);
}



void AdminPage::addOrder() {
    string orderId;
    string customerId;
    string note;
    double total;
    cout << "请输入订单编号：";
    cin >> orderId;
    cout << "请输入顾客用户名：";
    cin >> customerId;
    cout << "请输入订单备注：";
    cin >> note;
    StatusCode statusCode = orderController->addOrder(Order(orderId, customerId, note, Time(), total, OrderStatus::UNPAID));
    if (statusCode.isSuccess()) {
        cout << "添加成功" << endl;
    } else {
        cout << "添加失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void AdminPage::deleteOrder() {
    string orderId;
    cout << "请输入订单编号：";
    cin >> orderId;
    StatusCode statusCode = orderController->deleteOrder(orderId);
    if (statusCode.isSuccess()) {
        cout << "删除成功" << endl;
    } else {
        cout << "删除失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void AdminPage::updateOrder() {
    string originOrderId;
    string orderId;
    string customerId;
    string note;
    double total;
    int status;
    cout << "请输入原订单编号：";
    cin >> originOrderId;
    cout<< "原订单信息" << endl;

    Order order = orderController->getOrderById(originOrderId);
    if(order.getOrderId().empty()){
        cout << "订单不存在" << endl;
        return;
    }
    ShowTable::printTable({order.fields(), order.toVector()});

    cout << "请输入新订单编号：";
    cin >> orderId;
    cout << "请输入新顾客用户名：";
    cin >> customerId;
    cout << "请输入新订单备注：";
    cin >> note;
    cout << "订单状态 0-未支付 1-已支付 2-已发货 3-已收货 4-已取消"<< endl;
    cout << "请输入新订单状态：";
    cin >> status;
    StatusCode statusCode = orderController->updateOrder(Order(orderId, customerId, note, Time(), total, (OrderStatus) status), originOrderId);
    if (statusCode.isSuccess()) {
        cout << "修改成功" << endl;
    } else {
        cout << "修改失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void AdminPage::showAllOrders() {
    vector<Order> orders = orderController->getAllOrders();
    vector<vector<string>> table;
    table.push_back(Order::fields());
    for (Order order : orders) {
        table.push_back(order.toVector());
    }
    ShowTable::printTable(table);
}

void AdminPage::addOrderItem() {
    string orderItemId;
    string orderId;
    string commodityId;
    string commodityName;
    int quantity;
    double originalPrice;
    double discount;
    double discountPrice;
    double total;

    cout << "请输入订单项编号：";
    cin >> orderItemId;
    cout << "请输入订单编号：";
    cin >> orderId;
    cout << "请输入商品编号：";
    cin >> commodityId;
    cout << "请输入商品数量：";
    cin >> quantity;
    cout << "请输入商品折扣：";
    cin >> discount;

    Commodity commodity = commodityController->getCommodityById(commodityId);
    if(commodity.getId().empty()){
        cout << "商品不存在" << endl;
        return;
    }
    commodityName = commodity.getName();
    originalPrice = commodity.getPrice();
    discountPrice = originalPrice * discount;
    total = discountPrice * quantity;

    StatusCode statusCode = orderController->addOrderItem(OrderItem(orderItemId, orderId, commodityId, commodityName, quantity, originalPrice, discount, discountPrice, total));
    if (statusCode.isSuccess()) {
        cout << "添加成功" << endl;
    } else {
        cout << "添加失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void AdminPage::deleteOrderItem() {
    string orderItemId;
    cout << "请输入订单项编号：";
    cin >> orderItemId;
    StatusCode statusCode = orderController->deleteOrderItem(orderItemId);
    if (statusCode.isSuccess()) {
        cout << "删除成功" << endl;
    } else {
        cout << "删除失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void AdminPage::updateOrderItem() {
    string originOrderItemId;
    string orderItemId;
    string orderId;
    string commodityId;
    string commodityName;
    int quantity;
    double originalPrice;
    double discount;
    double discountPrice;
    double total;

    cout << "请输入原订单项编号：";
    cin >> originOrderItemId;
    cout<< "原订单项信息" << endl;

    OrderItem orderItem = orderController->getOrderItemById(originOrderItemId);
    if(orderItem.getOrderItemId().empty()){
        cout << "订单项不存在" << endl;
        return;
    }
    ShowTable::printTable({orderItem.fields(), orderItem.toVector()});

    cout << "请输入新订单项编号：";
    cin >> orderItemId;
    cout << "请输入新订单编号：";
    cin >> orderId;
    cout << "请输入新商品编号：";
    cin >> commodityId;
    cout << "请输入新商品数量：";
    cin >> quantity;
    cout << "请输入新商品折扣：";
    cin >> discount;

    Commodity commodity = commodityController->getCommodityById(commodityId);
    if(commodity.getId().empty()){
        cout << "商品不存在" << endl;
        return;
    }
    commodityName = commodity.getName();
    originalPrice = commodity.getPrice();
    discountPrice = originalPrice * discount;
    total = discountPrice * quantity;

    StatusCode statusCode = orderController->updateOrderItem(OrderItem(orderItemId, orderId, commodityId, commodityName, quantity, originalPrice, discount, discountPrice, total), originOrderItemId);
    if (statusCode.isSuccess()) {
        cout << "修改成功" << endl;
    } else {
        cout << "修改失败" << endl;
        cout << statusCode.getMessage() << endl;
    }
}

void AdminPage::showAllOrderItems() {
    vector<OrderItem> orderItems = orderController->getAllOrderItems();
    vector<vector<string>> table;
    table.push_back(OrderItem::fields());
    for (OrderItem orderItem : orderItems) {
        table.push_back(orderItem.toVector());
    }
    ShowTable::printTable(table);
}

void AdminPage::showOrderItemsByOrderId() {
    string orderId;
    cout << "请输入订单编号：";
    cin >> orderId;
    vector<OrderItem> orderItems = orderController->getAllOrderItemsByOrderId(orderId);
    vector<vector<string>> table;
    table.push_back(OrderItem::fields());
    for (OrderItem orderItem : orderItems) {
        table.push_back(orderItem.toVector());
    }
    ShowTable::printTable(table);
}

void AdminPage::showOrderDetails() {
    string orderId;
    cout << "请输入订单编号：";
    cin >> orderId;
    cout<< "订单信息" << endl;
    Order order = orderController->getOrderById(orderId);
    if(order.getOrderId().empty()){
        cout << "订单不存在" << endl;
        return;
    }
    ShowTable::printTable({order.fields(), order.toVector()});
    vector<OrderItem> orderItems = orderController->getAllOrderItemsByOrderId(orderId);
    vector<vector<string>> table;
    table.push_back(OrderItem::fields());
    for (OrderItem orderItem : orderItems) {
        table.push_back(orderItem.toVector());
    }
    ShowTable::printTable(table);
}

