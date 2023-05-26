#include "Event.h"

Event::Event(const Time &time, EventType type, const string &client) : time(time), type(type), client(client) {}

ostream &operator<<(ostream &os, const Event &event) {
    os << event.time << " " << static_cast<int>(event.type)<< " " << event.client;
    return os;
}

const Time &Event::getTime() const {
    return time;
}

EventType Event::getType() const {
    return type;
}

const string &Event::getClient() const {
    return client;
}

