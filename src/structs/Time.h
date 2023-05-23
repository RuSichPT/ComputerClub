#ifndef COMPUTERCLUB_TIME_H
#define COMPUTERCLUB_TIME_H

#include <ctime>
#include <ostream>
#include <iomanip>

using namespace std;

struct Time {
    int hour;
    int min;

    friend ostream &operator<<(ostream &os, const Time &time) {
        os << setfill('0') << setw(2) << time.hour << ":" << setfill('0') << setw(2) << time.min;
        return os;
    }

    Time operator+(const Time &time) const {
        Time newTime{};
        int allMin = (hour * 60 + min) + (time.hour * 60 + time.min);

        newTime.hour = (allMin / 60) % 24;
        newTime.min = allMin % 60;

        return newTime;
    }

    Time operator-(const Time &time) const {
        Time newTime{};
        int allMin = abs((hour * 60 + min) - (time.hour * 60 + time.min));

        newTime.hour = (allMin / 60) % 24;
        newTime.min = allMin % 60;

        return newTime;
    }

    bool operator<(const Time &rhs) const {
        if (hour < rhs.hour)
            return true;
        if (rhs.hour < hour)
            return false;
        return min < rhs.min;
    }

    bool operator>(const Time &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Time &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Time &rhs) const {
        return !(*this < rhs);
    }
};


#endif //COMPUTERCLUB_TIME_H
