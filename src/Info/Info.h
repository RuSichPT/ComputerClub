#ifndef COMPUTERCLUB_INFO_H
#define COMPUTERCLUB_INFO_H


#include "../structs/Time.h"
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
    Time start{};
    Time end{};
    int numTables;
    vector<Event> events;
    int hourCost{};
    unique_ptr<FileParser> parser;

    void getTimeFromStringVector(Time &time, const vector<string> &vector, int index);
};


#endif //COMPUTERCLUB_INFO_H
