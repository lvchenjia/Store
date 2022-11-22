//
// Created by Horse on 2022/11/19.
//

#ifndef TIME_H
#define TIME_H

#include "Utility.h"
#include <time.h>
#include <string>
using namespace std;

class Time {
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
public:
    Time();

    Time(int year, int month, int day, int hour, int minute, int second);

    Time(string time);

    int getYear() const;

    void setYear(int year);

    int getMonth() const;

    void setMonth(int month);

    int getDay() const;

    void setDay(int day);

    int getHour() const;

    void setHour(int hour);

    int getMinute() const;

    void setMinute(int minute);

    int getSecond() const;

    void setSecond(int second);

    string toString() const;
};

#endif
