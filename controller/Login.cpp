#include "Login.h"

Login::Login() {
    database = new Database();
}

Login::LoginStatus Login::login(const string &username, const string &password) {
    try{
        QueryResult result = database->select("select username, password, identity from users where username = '" + username + "'");
        if(result.rows.empty()) {
            return USERNAME_ERROR;
        }
        if(result.rows[0][1] != password) {
            return PASSWORD_ERROR;
        }
        curUser = new User(result.rows[0][0], result.rows[0][1], (User::UserIdentity)stoi(result.rows[0][2]));
        return SUCCESS;
    }catch (DbException e){
        cout << e.what() << endl;
        return DATABASE_ERROR;
    }
}

User *Login::getCurUserInfo() const {
    return curUser;
}