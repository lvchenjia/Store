//
// Created by Horse on 2022/11/21.
//

#ifndef STORE_STATUSCODE_H
#define STORE_STATUSCODE_H

#include <string>
using namespace std;

class StatusCode {
private:
    int code;
    string message;
public:
    StatusCode(int code, const string& message);

    int getCode() const;

    void setCode(int code);

    const string &getMessage() const;

    void setMessage(const string &message);

    bool isSuccess();
};


#endif //STORE_STATUSCODE_H
