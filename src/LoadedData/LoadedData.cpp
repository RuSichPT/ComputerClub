#include "LoadedData.h"
#include <algorithm>
#include "../Event/EventCome.h"
#include "../Event/EventSit.h"
#include "../Event/EventWait.h"

LoadedData::LoadedData(const string &path) {
    parser = make_unique<FileParser>(path);
    const vector<string> &strings = parser->getStrings();

    for (int i = 0; i < strings.size(); ++i) {
        const string &item = strings.at(i);
        if (i == 0) {
            numTables = stoi(item);
        } else if (i == 2) {
            hourCost = stoi(item);
        } else {
            vector<string> splitStr;
            parser->split(item, ' ', splitStr);

            if (i == 1) {
                start = Time(splitStr.at(0));
                end = Time(splitStr.at(1));
            } else {
                if (!createEvent(splitStr)){
                    throw runtime_error(item);
                };
            }
        }
    }
}

const Time &LoadedData::getStart() const {
    return start;
}

int LoadedData::getNumTables() const {
    return numTables;
}

const Time &LoadedData::getEnd() const {
    return end;
}

int LoadedData::getHourCost() const {
    return hourCost;
}

bool LoadedData::createEvent(const vector<string> &splitStr) {
    static Time previousTime{};
    Time time = Time(splitStr.at(0));
    if ((time < previousTime)){
        return false;
    }

    auto type = static_cast<EventType>(stoi(splitStr.at(1)));
    string client = splitStr.at(2);

    shared_ptr<Event> event;
    if (type == EventType::COME) {
        event = make_shared<EventCome>(time, client);
    } else if (type == EventType::SIT) {
        int tableNumber = stoi(splitStr.at(3));
        event = make_shared<EventSit>(time, client, tableNumber);
    } else if (type == EventType::WAIT) {
        event = make_shared<EventWait>(time, client);
    }

    events.push_back(event);

    return true;
}

const vector<shared_ptr<Event>> &LoadedData::getEvents() const {
    return events;
}



