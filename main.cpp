#include "view/LoginPage.h"
#include "view/AdminPage.h"

using namespace std;
int main() {
    system("chcp 65001");//设置控制台编码为utf-8
    system("clear");

//    LoginPage loginPage;
//    loginPage.show();

    Administrator *admin = new Administrator("admin", "admin");
    AdminPage adminPage(admin);
    adminPage.show();

    return 0;
}
