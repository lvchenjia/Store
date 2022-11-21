#include "Time.h"

Time::Time() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
    hour = ltm->tm_hour;
    minute = ltm->tm_min;
    second = ltm->tm_sec;
}

Time::Time(int year, int month, int day, int hour, int minute, int second) : year(year),
                                                                          month(month),
                                                                          day(day),
                                                                          hour(hour),
                                                                          minute(minute),
                                                                          second(second) {}

int Time::getYear() const {
    return year;
}

void Time::setYear(int year) {
    Time::year = year;
}

int Time::getMonth() const {
    return month;
}

void Time::setMonth(int month) {
    Time::month = month;
}

int Time::getDay() const {
    return day;
}

void Time::setDay(int day) {
    Time::day = day;
}

int Time::getHour() const {
    return hour;
}

void Time::setHour(int hour) {
    Time::hour = hour;
}

int Time::getMinute() const {
    return minute;
}

void Time::setMinute(int minute) {
    Time::minute = minute;
}

int Time::getSecond() const {
    return second;
}

void Time::setSecond(int second) {
    Time::second = second;
}

string Time::toString() {
    string s = to_string(year) + "-" + to_string(month) + "-" + to_string(day) + " " + to_string(hour) + ":" +
               to_string(minute) + ":" + to_string(second);
    return s;
}
