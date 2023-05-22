#ifndef COMPUTERCLUB_EVENTS_H
#define COMPUTERCLUB_EVENTS_H

#include <string>
#include <ostream>
#include "EventType.h"

using namespace std;

struct Event {
    string time;
    EventType type;
    string body;

    friend ostream &operator<<(ostream &os, const Event &event) {
        os << event.time << " " << static_cast<int>(event.type) << " " << event.body;
        return os;
    }
};

#endif //COMPUTERCLUB_EVENTS_H
