#ifndef COMPUTERCLUB_TABLE_H
#define COMPUTERCLUB_TABLE_H

#include <string>
#include <ostream>
#include "../Time/Time.h"

class Table {
public:
    explicit Table(int number);

    void take(const string &client1, const Time &start1);

    void release(const Time &end, int price);

    int getNumber() const;

    bool isBusy() const;

    const string &getClient() const;

    const Time &getStart() const;

    const Time &getDuration() const;

    int getProfit() const;

    friend ostream &operator<<(ostream &os, const Table &table);

private:
    int number;
    bool busy = false;
    string client;
    Time start;
    Time duration;
    int profit = 0;
};


#endif //COMPUTERCLUB_TABLE_H
