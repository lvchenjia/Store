#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
using namespace std;
class User {
public:
    enum UserIdentity {
        ADMIN, CUSTOMER
    };
    User(vector<string> &row);
    User(const string &username, const string &password, UserIdentity identity);

    const string &getUsername() const;
    void setUsername(const string &username);
    const string &getPassword() const;
    void setPassword(const string &password);
    UserIdentity getIdentity() const;
    void setIdentity(UserIdentity identity);



private:
    string username;
    string password;
    UserIdentity identity;
};


#endif
