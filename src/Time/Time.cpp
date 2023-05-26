#include "Time.h"
#include <iomanip>
#include <regex>

Time::Time(int hour, int min) : hour(hour), min(min) {}

Time::Time(const string &time) {
    static const regex r("[0-9]{2}[:]{1}[0-9]{2}");
    if (!regex_match(time, r)) {
        throw runtime_error(time);
    }
    hour = stoi(time.substr(0, 2));
    min = stoi(time.substr(3, 4));
}

Time Time::operator+(const Time &time) const {
    int allMin = (hour * 60 + min) + (time.hour * 60 + time.min);

    int hour_l = (allMin / 60) % 24;
    int min_l = allMin % 60;

    return Time(hour_l, min_l);
}

Time Time::operator-(const Time &time) const {
    int allMin = abs((hour * 60 + min) - (time.hour * 60 + time.min));

    int hour_l = (allMin / 60) % 24;
    int min_l = allMin % 60;

    return Time(hour_l, min_l);
}

bool Time::operator<(const Time &rhs) const {
    if (hour < rhs.hour)
        return true;
    if (rhs.hour < hour)
        return false;
    return min < rhs.min;
}

bool Time::operator>(const Time &rhs) const {
    return rhs < *this;
}

bool Time::operator<=(const Time &rhs) const {
    return !(rhs < *this);
}

bool Time::operator>=(const Time &rhs) const {
    return !(*this < rhs);
}

ostream &operator<<(ostream &os, const Time &time) {
    os << setfill('0') << setw(2) << time.hour << ":" << setfill('0') << setw(2) << time.min;
    return os;
}

int Time::getHour() const {
    return hour;
}

int Time::getMin() const {
    return min;
}

