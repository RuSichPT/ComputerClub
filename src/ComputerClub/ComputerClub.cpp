#include "ComputerClub.h"
#include <algorithm>
#include <iostream>
#include "../Enums/EventType.h"
#include "../Event/EventError.h"

ComputerClub::ComputerClub(const Time &start, const Time &anEnd, int numTables, int hourCost)
        : start(start), end(anEnd), numTables(numTables), hourCost(hourCost) {
    initTables();
}

const Time &ComputerClub::getStart() const {
    return start;
}

const Time &ComputerClub::getEnd() const {
    return end;
}

void ComputerClub::add(const string &client) {
    capacity.push_back(client);
}

void ComputerClub::remove(const string &client) {
    auto iCapacity = find(capacity.begin(), capacity.end(), client);
    if (iCapacity == capacity.end()) {
        throw runtime_error("ClientUnknown");
    } else {
        capacity.erase(iCapacity);
    }
}

bool ComputerClub::hasClient(const string &client) const {
    return find(capacity.begin(), capacity.end(), client) != capacity.end();
}

void ComputerClub::takeTable(const string &client, const Time &start, int tableNumber) {
    if (tableNumber > numTables) {
        throw runtime_error("table number must not exceed the number of tables");
    }

    auto isTableNumber = [&tableNumber](const Table &table) { return table.getNumber() == tableNumber; };
    auto iTable = find_if(tables.begin(), tables.end(), isTableNumber);

    if (iTable != tables.end()) {
        if (iTable->isBusy()) {
            throw runtime_error("PlaceIsBusy");
        } else {
            iTable->take(client, start);
        }
    }
}

bool ComputerClub::hasFreeTables() const {
    auto isFree = [](const Table &table) { return !table.isBusy(); };
    return find_if(tables.begin(), tables.end(), isFree) != tables.end();
}

void ComputerClub::takeQueue(const string &client, const Time &start) {
    if (queue.size() > tables.size()) {
        throw runtime_error("");
//        generateEvent(event.time, EventType::END_DAY_OR_LEAVE, "");
    } else {
        queue.push(client);
    }
}

void ComputerClub::releaseTable(const string &client, const Time &end) {

    auto isClient = [&client](const Table &table) { return table.getClient() == client; };
    auto iTable = find_if(tables.begin(), tables.end(), isClient);

//    if (iTable != tables.end()) {
//        if (!queue.empty()) {
//            string clientFromQueue = queue.front();
//            queue.pop();
//            iTable->release(end, hourCost);
//            iTable->take(clientFromQueue, end);
//            throw
//                    generateEvent(event.time, EventType::QUEUE, client + " " + to_string(iTable->getNumber()));
//        } else {
//            iTable->release(event.time, info.getHourCost());
//        }
//    }
}

void ComputerClub::initTables() {
    for (int i = 0; i < numTables; ++i) {
        Table table(i + 1);
        tables.push_back(table);
    }
}

void ComputerClub::printProfit() {
    for (auto &table: tables) {
        cout << table << endl;
    }
}

void ComputerClub::endDay() {
    for (auto &table: tables) {
        if (table.isBusy()) {
//            cout << EventError(end,) <<
//            generateEvent(end, EventType::END_DAY_OR_LEAVE, table.getClient());
            table.release(end, hourCost);
        }
    }
}
