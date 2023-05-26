#ifndef COMPUTERCLUB_EVENTLEAVE_H
#define COMPUTERCLUB_EVENTLEAVE_H


#include "Event.h"

class EventLeave : public Event {
public:
    EventLeave(const Time &time, const string &client);

    void handle(shared_ptr<ComputerClub> &info) override;
};


#endif //COMPUTERCLUB_EVENTLEAVE_H
