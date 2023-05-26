#ifndef COMPUTERCLUB_LOADEDDATA_H
#define COMPUTERCLUB_LOADEDDATA_H

#include <memory>
#include <queue>
#include "../FileParser/FileParser.h"
#include "../Event/Event.h"
#include "../Table/Table.h"

class LoadedData {
public:
    explicit LoadedData(const string &path);

    const Time &getStart() const;

    int getNumTables() const;

    const Time &getEnd() const;

    const vector<shared_ptr<Event>> &getEvents() const;

    int getHourCost() const;

private:
    Time start;
    Time end;
    int numTables;
    vector<shared_ptr<Event>> events;
    int hourCost;
    unique_ptr<FileParser> parser;

    bool createEvent(const vector<string> &splitStr);
};


#endif //COMPUTERCLUB_LOADEDDATA_H
