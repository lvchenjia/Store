#include<exception>
#include <string>
_Pragma("once")
using namespace std;
class DbException: public exception
{
public:
    DbException(const char* msg):err_msg(msg){}
    DbException(string msg) :err_msg(msg) {}
    const char* what() const throw(){return err_msg.c_str(); }
    string getMsg() const { return err_msg; }
private:
    string err_msg;
};
