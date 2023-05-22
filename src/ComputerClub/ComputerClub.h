#ifndef COMPUTERCLUB_COMPUTERCLUB_H
#define COMPUTERCLUB_COMPUTERCLUB_H

#include <string>
#include <memory>
#include <ctime>
#include "../FileParser/FileParser.h"
#include "../EventsHandler/EventsHandler.h"
#include "../structs/Events.h"

using namespace std;

class ComputerClub {
public:
    explicit ComputerClub(const string &path);
    void open();

private:
    int numTables{};
    int hourlyCost{};
    Time start;
    Time end;
    vector<Event> events;
    unique_ptr<FileParser> parser;
    unique_ptr<EventsHandler> handler;
};


#endif //COMPUTERCLUB_COMPUTERCLUB_H
