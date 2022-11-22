#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include <vector>
using namespace std;
class Administrator {
public:
    Administrator(const string &username, const string &password);

    const string &getUsername() const;

    void setUsername(const string &username);

    const string &getPassword() const;

    void setPassword(const string &password);

    vector<string> toVector() const;

    static vector<string> fields();

private:
    string username;
    string password;
};

#endif
