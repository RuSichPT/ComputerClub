#include "Info.h"

Info::Info(const string &path) {
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
                Time time = Time(splitStr.at(0));
                checkSequence(time,splitStr.at(0));
                auto type = static_cast<EventType>(stoi(splitStr.at(1)));
                int numberTable = 0;
                if (type == EventType::SIT) {
                    numberTable = stoi(splitStr.at(3));
                }
                Event event{time, type, splitStr.at(2), numberTable};
                events.push_back(event);
            }
        }
    }
}

const Time &Info::getStart() const {
    return start;
}

int Info::getNumTables() const {
    return numTables;
}

const Time &Info::getEnd() const {
    return end;
}

const vector<Event> &Info::getEvents() const {
    return events;
}

int Info::getHourCost() const {
    return hourCost;
}

void Info::checkSequence(const Time &time, const string &str) {
    static Time previousTime{};
    if (time > previousTime) {
        previousTime = time;
    } else {
        throw runtime_error(str);
    }
}
