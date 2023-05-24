#ifndef COMPUTERCLUB_INFO_H
#define COMPUTERCLUB_INFO_H

#include <memory>
#include "../FileParser/FileParser.h"
#include "../structs/Events.h"

class Info {
public:
    explicit Info(const string &path);

    const Time &getStart() const;

    int getNumTables() const;

    const Time &getEnd() const;

    const vector<Event> &getEvents() const;

    int getHourCost() const;

private:
    Time start;
    Time end;
    int numTables;
    vector<Event> events;
    int hourCost{};
    unique_ptr<FileParser> parser;

    void checkSequence(const Time &time, const string &str);
};


#endif //COMPUTERCLUB_INFO_H
