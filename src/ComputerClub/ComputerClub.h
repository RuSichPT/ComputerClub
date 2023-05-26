#ifndef COMPUTERCLUB_COMPUTERCLUB_H
#define COMPUTERCLUB_COMPUTERCLUB_H

#include <string>
#include <memory>
#include <ctime>
#include <queue>
#include "../Time/Time.h"
#include "../Table/Table.h"

using namespace std;

class ComputerClub {
public:
    ComputerClub(const Time &start, const Time &anEnd, int numTables, int hourCost);

    const Time &getStart() const;

    const Time &getEnd() const;

    void add(const string &client);

    void remove(const string &client);

    bool hasClient(const string &client) const;

    bool hasFreeTables() const;

    void takeTable(const string &client, const Time &start, int tableNumber);

    void releaseTable(const string &client, const Time &end);

    void takeQueue(const string &client, const Time &start);

    void printProfit();

    void endDay();

private:
    Time start;
    Time end;
    int numTables;
    int hourCost;

    vector<Table> tables;
    vector<string> capacity;
    queue<string> queue;

    void initTables();
};


#endif //COMPUTERCLUB_COMPUTERCLUB_H
