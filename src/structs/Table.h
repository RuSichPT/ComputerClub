#ifndef COMPUTERCLUB_TABLE_H
#define COMPUTERCLUB_TABLE_H

#include <queue>
#include <string>

using namespace std;

struct Table {
    int number;
    bool isBusy = false;
    string client;
    Time start;
    Time duration;
    int profit = 0;

    void take(const string &client1, const Time &start1) {
        isBusy = true;
        client = client1;
        start = start1;
    }

    void release(const Time &end, int price) {
        isBusy = false;
        client = "";
        Time difference = end - start;
        duration = duration + difference;
        int hours = difference.hour;
        if (difference.min > 0) {
            hours++;
        }
        profit += price * hours;
    }
};

#endif //COMPUTERCLUB_TABLE_H
