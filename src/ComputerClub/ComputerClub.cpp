#include "ComputerClub.h"
#include <iostream>
#include <algorithm>

ComputerClub::ComputerClub(const string &path) {
    parser = make_unique<FileParser>(path);
    handler = make_unique<EventsHandler>();
}

void ComputerClub::open() {
    const vector<string> &strings = parser->getStrings();

    for (int i = 0; i < strings.size(); ++i) {
        const string &item = strings.at(i);
        if (i == 0) {
            initTables(stoi(item));
        } else if (i == 1) {
            vector<string> allTime;
            parser->split(item, ' ', allTime);
            start.hour = stoi(allTime.at(0).substr(0, 2));
            start.min = stoi(allTime.at(0).substr(3, 4));
            end.hour = stoi(allTime.at(1).substr(0, 2));
            end.min = stoi(allTime.at(1).substr(3, 4));
        } else if (i == 2) {
            hourlyCost = stoi(item);
        } else {
            vector<string> str;
            parser->split(item, ' ', str);
            Time time{};
            time.hour = stoi(str.at(0).substr(0, 2));
            time.min = stoi(str.at(0).substr(3, 4));
            auto type = static_cast<EventType>(stoi(str.at(1)));
            int numberTable = 0;
            if (type == EventType::SIT) {
                numberTable = stoi(str.at(3));
            }
            Event event{time, type, str.at(2), numberTable};
            events.push_back(event);
        }
    }
    cout << start << endl;
//    handler->handle(events);
    handleEvents();
    for (auto &table: tables) {
        if (table.isBusy) {
            generateEvent(end, EventType::END_DAY_OR_LEAVE, table.client);
            table.release(end, hourlyCost);
        }
    }
    cout << end << endl;

    for (auto &table: tables) {
        cout << table.number << ' ' << table.profit << ' ' << table.duration << endl;
    }
}

void ComputerClub::initTables(int numTables) {
    for (int i = 0; i < numTables; ++i) {
        Table table{i + 1};
        tables.push_back(table);
    }
}

void ComputerClub::handleEvents() {
    for (auto &event: events) {
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
    if (event.time < start) {
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

    auto clientWantToSit = [&event](const Table &table) { return table.number == event.body.numberTable; };
    auto iTable = find_if(tables.begin(), tables.end(), clientWantToSit);

    if (iTable->isBusy) {
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
    auto isFree = [](const Table &table) { return !table.isBusy; };
    return find_if(tables.begin(), tables.end(), isFree) != tables.end();
}

void ComputerClub::handleLeave(const Event &event) {
    if (find(capacity.begin(), capacity.end(), event.body.client) == capacity.end()) {
        generateEvent(event.time, EventType::ERROR, "ClientUnknown");
        return;
    }

    auto clientWantToLeave = [&event](const Table &table) { return table.client == event.body.client; };
    auto iTable = find_if(tables.begin(), tables.end(), clientWantToLeave);

    if (!queue.empty()) {
        string client = queue.front();
        queue.pop();
        iTable->release(event.time, hourlyCost);
        iTable->take(client,event.time);
        generateEvent(event.time, EventType::QUEUE, client + " " + to_string(iTable->number));
    } else {
        iTable->release(event.time, hourlyCost);
    }
}
