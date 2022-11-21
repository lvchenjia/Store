#include "Customer.h"

Customer::Customer(const string &username, const string &password, const string &nickname, const string &address,
                   const string &phone) : username(username), password(password), nickname(nickname), address(address),
                                          phone(phone) {}

const string &Customer::getUsername() const {
    return username;
}

void Customer::setUsername(const string &username) {
    Customer::username = username;
}

const string &Customer::getPassword() const {
    return password;
}

void Customer::setPassword(const string &password) {
    Customer::password = password;
}

const string &Customer::getNickname() const {
    return nickname;
}

void Customer::setNickname(const string &nickname) {
    Customer::nickname = nickname;
}

const string &Customer::getAddress() const {
    return address;
}

void Customer::setAddress(const string &address) {
    Customer::address = address;
}

const string &Customer::getPhone() const {
    return phone;
}

void Customer::setPhone(const string &phone) {
    Customer::phone = phone;
}
