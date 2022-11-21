#include <string>
using namespace std;
class Admin {
public:
    Admin(const string &username, const string &password);

    const string &getUsername() const;

    void setUsername(const string &username);

    const string &getPassword() const;

    void setPassword(const string &password);

private:
    string username;
    string password;
};
