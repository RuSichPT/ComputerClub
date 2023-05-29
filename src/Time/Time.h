#ifndef COMPUTERCLUB_TIME_H
#define COMPUTERCLUB_TIME_H

#include <ostream>

using namespace std;

class Time {
public:
    explicit Time(int hour = 0, int min = 0);

    explicit Time(const string &time);

    Time operator+(const Time &time) const;

    Time operator-(const Time &time) const;

    bool operator<(const Time &rhs) const;

    bool operator>(const Time &rhs) const;

    bool operator<=(const Time &rhs) const;

    bool operator>=(const Time &rhs) const;

    friend ostream &operator<<(ostream &os, const Time &time);

    int getHour() const;

    int getMin() const;

    bool operator==(const Time &rhs) const;

    bool operator!=(const Time &rhs) const;

private:
    int hour;
    int min;
};


#endif //COMPUTERCLUB_TIME_H
