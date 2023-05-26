#ifndef COMPUTERCLUB_EVENT_H
#define COMPUTERCLUB_EVENT_H

#include <ostream>
#include "../Time/Time.h"
#include "../Enums/EventType.h"
#include "../ComputerClub/ComputerClub.h"

class Event {
public:
    Event(const Time &time, EventType type, const string &body);

    virtual void handle(shared_ptr<ComputerClub> &club) = 0;

    virtual string toString() const;

    const Time &getTime() const;

    EventType getType() const;

    const string &getBody() const;

    friend ostream &operator<<(ostream &os, const Event &event);

private:
    Time time;
    EventType type = EventType::NONE;
    string body;
};


#endif //COMPUTERCLUB_EVENT_H
