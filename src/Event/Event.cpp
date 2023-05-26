#include <sstream>
#include "Event.h"

Event::Event(const Time &time, EventType type, const string &body) : time(time), type(type), body(body) {}

ostream &operator<<(ostream &os, const Event &event) {
    os << event.toString();
    return os;
}

const Time &Event::getTime() const {
    return time;
}

EventType Event::getType() const {
    return type;
}

const string &Event::getBody() const {
    return body;
}

string Event::toString() const {
    ostringstream os;
    os << time << " " << static_cast<int>(type) << " " << body;
    return os.str();
}

