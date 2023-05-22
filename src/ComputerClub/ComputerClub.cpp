#include "ComputerClub.h"
#include <iostream>

ComputerClub::ComputerClub(const string &path) {
    parser = make_unique<FileParser>(path);
    handler = make_unique<EventsHandler>();
}

void ComputerClub::open() {
    const vector<string> &strings = parser->getStrings();

    for (int i = 0; i < strings.size(); ++i) {
        const string &item = strings.at(i);
        if (i == 0) {
            numTables = stoi(item);
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
            Event event{time, static_cast<EventType>(stoi(str.at(1))), str.at(2)};
            events.push_back(event);
        }
    }
    cout << start << endl;
    handler->handle(events);
    cout << end << endl;
}
