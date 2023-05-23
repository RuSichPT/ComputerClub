#ifndef COMPUTERCLUB_COMPUTERCLUB_H
#define COMPUTERCLUB_COMPUTERCLUB_H

#include <string>
#include <memory>
#include <ctime>
#include "../FileParser/FileParser.h"
#include "../EventsHandler/EventsHandler.h"
#include "../structs/Events.h"
#include "../structs/Table.h"

using namespace std;

class ComputerClub {
public:
    explicit ComputerClub(const string &path);

    void open();

private:
    vector<Table> tables;
    vector<string> capacity;
    queue<string> queue;
    int hourlyCost{};
    Time start{};
    Time end{};
    vector<Event> events;
    unique_ptr<FileParser> parser;
    unique_ptr<EventsHandler> handler;

    void initTables(int numTables);

    void generateEvent(const Time &time, EventType type, const string &body);

    bool hasFreeTables();

    void handleEvents();

    void handleCome(const Event &event);

    void handleSit(const Event &event);

    void handleWait(const Event &event);

    void handleLeave(const Event &event);
};


#endif //COMPUTERCLUB_COMPUTERCLUB_H
