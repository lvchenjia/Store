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

vector<string> Customer::toVector() const {
    vector<string> result;
    result.push_back(username);
    result.push_back(password);
    result.push_back(nickname);
    result.push_back(address);
    result.push_back(phone);
    return result;
}

vector<string> Customer::fields() {
    vector<string> result;
    result.push_back("username");
    result.push_back("password");
    result.push_back("nickname");
    result.push_back("address");
    result.push_back("phone");
    return result;
}

