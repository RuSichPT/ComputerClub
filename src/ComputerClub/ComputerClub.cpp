#include "ComputerClub.h"
#include <iostream>
#include <algorithm>

ComputerClub::ComputerClub(const string &path)
        : info(path) {
    handler = make_unique<EventsHandler>();
    initTables(info.getNumTables());
}

void ComputerClub::open() {
    cout << info.getStart() << endl;
//    handler->handle(events);
    handleEvents();
}

void ComputerClub::initTables(int numTables) {
    for (int i = 0; i < numTables; ++i) {
        Table table(i + 1);
        tables.push_back(table);
    }
}

void ComputerClub::handleEvents() {
    for (auto &event: info.getEvents()) {
        cout << event << endl;

        if (event.type == EventType::COME) {
            handleCome(event);
        } else if (event.type == EventType::SIT) {
            handleSit(event);
        } else if (event.type == EventType::WAIT) {
            handleWait(event);
        } else if (event.type == EventType::LEAVE) {
            handleLeave(event);
        }
    }
}

void ComputerClub::generateEvent(const Time &time, EventType type, const string &body) {
    Event error{time, type, body};
    cout << error << endl;
}

void ComputerClub::handleCome(const Event &event) {
    if (event.time < info.getStart()) {
        generateEvent(event.time, EventType::ERROR, "NotOpenYet");
    } else if (find(capacity.begin(), capacity.end(), event.body.client) == capacity.end()) {
        capacity.push_back(event.body.client);
    } else {
        generateEvent(event.time, EventType::ERROR, "YouShallNotPass");
    }
}

void ComputerClub::handleSit(const Event &event) {
    if (find(capacity.begin(), capacity.end(), event.body.client) == capacity.end()) {
        generateEvent(event.time, EventType::ERROR, "ClientUnknown");
        return;
    }

    auto clientWantToSit = [&event](const Table &table) { return table.getNumber() == event.body.numberTable; };
    auto iTable = find_if(tables.begin(), tables.end(), clientWantToSit);

    if (iTable->isBusy()) {
        generateEvent(event.time, EventType::ERROR, "PlaceIsBusy");
    } else {
        iTable->take(event.body.client, event.time);
    }

}

void ComputerClub::handleWait(const Event &event) {
    if (hasFreeTables()) {
        generateEvent(event.time, EventType::ERROR, "ICanWaitNoLonger!");
    } else if (queue.size() > tables.size()) {
        generateEvent(event.time, EventType::END_DAY_OR_LEAVE, "");
    } else {
        queue.push(event.body.client);
    }
}

bool ComputerClub::hasFreeTables() {
    auto isFree = [](const Table &table) { return !table.isBusy(); };
    return find_if(tables.begin(), tables.end(), isFree) != tables.end();
}

void ComputerClub::handleLeave(const Event &event) {
    if (find(capacity.begin(), capacity.end(), event.body.client) == capacity.end()) {
        generateEvent(event.time, EventType::ERROR, "ClientUnknown");
        return;
    }

    auto clientWantToLeave = [&event](const Table &table) { return table.getClient() == event.body.client; };
    auto iTable = find_if(tables.begin(), tables.end(), clientWantToLeave);

    if (!queue.empty()) {
        string client = queue.front();
        queue.pop();
        iTable->release(event.time, info.getHourCost());
        iTable->take(client, event.time);
        generateEvent(event.time, EventType::QUEUE, client + " " + to_string(iTable->getNumber()));
    } else {
        iTable->release(event.time, info.getHourCost());
    }
}

void ComputerClub::close() {
    for (auto &table: tables) {
        if (table.isBusy()) {
            generateEvent(info.getEnd(), EventType::END_DAY_OR_LEAVE, table.getClient());
            table.release(info.getEnd(), info.getHourCost());
        }
    }
    cout << info.getEnd() << endl;

    for (auto &table: tables) {
        cout << table << endl;
    }
}
