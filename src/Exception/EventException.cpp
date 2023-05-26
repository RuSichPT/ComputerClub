#include "EventException.h"
#include <ostream>

EventException::EventException(EventType type, const string &message) : type(type), message(message) {}

const char *EventException::what() const noexcept {
    return message.c_str();
}

EventType EventException::getType() const {
    return type;
}
