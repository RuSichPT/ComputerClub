#ifndef COMPUTERCLUB_EVENTS_H
#define COMPUTERCLUB_EVENTS_H

#include <string>
#include <ostream>
#include "../enums/EventType.h"
#include "Time.h"

using namespace std;

struct Event {
    Time time;
    EventType type;
    string body;

    friend ostream &operator<<(ostream &os, const Event &event) {
        os << event.time << " " << static_cast<int>(event.type) << " " << event.body;
        return os;
    }
};

#endif //COMPUTERCLUB_EVENTS_H
