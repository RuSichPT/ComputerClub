#include "Table.h"

Table::Table(int number) : number(number) {

}

void Table::take(const string &client1, const Time &start1) {
    busy = true;
    client = client1;
    start = start1;
}

void Table::release(const Time &end, int price) {
    busy = false;
    client = "";
    Time difference = end - start;
    duration = duration + difference;
    int hours = difference.hour;
    if (difference.min > 0) {
        hours++;
    }
    profit += price * hours;
}

int Table::getNumber() const {
    return number;
}

bool Table::isBusy() const {
    return busy;
}

const string &Table::getClient() const {
    return client;
}

const Time &Table::getStart() const {
    return start;
}

const Time &Table::getDuration() const {
    return duration;
}

int Table::getProfit() const {
    return profit;
}

ostream &operator<<(ostream &os, const Table &table) {
    os << table.number << " " << table.profit << " " << table.duration;
    return os;
}

