#ifndef COMPUTERCLUB_EVENTEXCEPTION_H
#define COMPUTERCLUB_EVENTEXCEPTION_H


#include "../Event/Event.h"
#include <sstream>

class EventException : public exception {
public:
    EventException(EventType type, const string &message);

    EventType getType() const;

    const char *what() const noexcept override;

private:
    EventType type = EventType::ERROR;
    string message;
};


#endif //COMPUTERCLUB_EVENTEXCEPTION_H
