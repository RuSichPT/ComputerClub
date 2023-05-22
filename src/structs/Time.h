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
};


#endif //COMPUTERCLUB_TIME_H
