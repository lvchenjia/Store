//
// Created by Horse on 2022/11/21.
//

#include "StatusCode.h"

StatusCode::StatusCode(int code, const string &message) : code(code), message(message) {}

int StatusCode::getCode() const {
    return code;
}

void StatusCode::setCode(int code) {
    StatusCode::code = code;
}

const string &StatusCode::getMessage() const {
    return message;
}

void StatusCode::setMessage(const string &message) {
    StatusCode::message = message;
}

bool StatusCode::isSuccess() {
    return code == 0;
}
