#ifndef COMPUTERCLUB_EVENTS_H
#define COMPUTERCLUB_EVENTS_H

#include <string>
#include <ostream>
#include "../enums/EventType.h"
#include "../Time/Time.h"

using namespace std;

struct EventBody {
    string client;
    int numberTable;

    friend ostream &operator<<(ostream &os, const EventBody &body) {
        if (body.numberTable != 0) {
            os << body.client << " " << body.numberTable;
        } else {
            os << body.client;
        }
        return os;
    }
};

struct Event {
    Time time;
    EventType type = EventType::NONE;
    EventBody body;

    friend ostream &operator<<(ostream &os, const Event &event) {
        os << event.time << " " << static_cast<int>(event.type) << " " << event.body;
        return os;
    }
};

#endif //COMPUTERCLUB_EVENTS_H
