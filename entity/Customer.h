#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
public:
    Customer(const string &username, const string &password, const string &nickname, const string &address,
             const string &phone);

    const string &getUsername() const;

    void setUsername(const string &username);

    const string &getPassword() const;

    void setPassword(const string &password);

    const string &getNickname() const;

    void setNickname(const string &nickname);

    const string &getAddress() const;

    void setAddress(const string &address);

    const string &getPhone() const;

    void setPhone(const string &phone);

public:

private:
    string username;
    string password;
    string nickname;
    string address;
    string phone;
};
#endif
