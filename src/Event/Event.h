#ifndef COMPUTERCLUB_EVENT_H
#define COMPUTERCLUB_EVENT_H

#include <ostream>
#include "../Time/Time.h"
#include "../Enums/EventType.h"
#include "../ComputerClub/ComputerClub.h"

class Event {
public:
    Event(const Time &time, EventType type, const string &client);

    friend ostream &operator<<(ostream &os, const Event &event);

    virtual void handle(shared_ptr<ComputerClub> &club) = 0;

    const Time &getTime() const;

    EventType getType() const;

    const string &getClient() const;

private:
    Time time;
    EventType type = EventType::NONE;
    string client;
};


#endif //COMPUTERCLUB_EVENT_H
