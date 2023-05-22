#include "ComputerClub.h"
#include <iostream>
#include <iomanip>

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

            time_t now = time(nullptr);
            start = *localtime(&now);
            end = start;
            start.tm_hour = stoi(allTime.at(0).substr(0, 2));
            start.tm_min = stoi(allTime.at(0).substr(3, 4));
            end.tm_hour = stoi(allTime.at(1).substr(0, 2));
            end.tm_min = stoi(allTime.at(1).substr(3, 4));
        } else if (i == 2) {
            hourlyCost = stoi(item);
        } else {
            vector<string> str;
            parser->split(item, ' ', str);
            Event event{str.at(0), static_cast<EventType>(stoi(str.at(1))), str.at(2)};
            events.push_back(event);
        }
    }
    cout << setfill('0') << setw(2) << start.tm_hour << ":"<< setfill('0') << setw(2)  << start.tm_min << endl;
    handler->handle(events);
    cout << setfill('0') << setw(2) << end.tm_hour << ":"<< setfill('0') << setw(2)  << end.tm_min << endl;
}
