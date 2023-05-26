#ifndef COMPUTERCLUB_EVENTCOME_H
#define COMPUTERCLUB_EVENTCOME_H


#include "Event.h"

class EventCome : public Event {
public:
    EventCome(const Time &time, const string &body);

    void handle(shared_ptr<ComputerClub> &club) override;
};


#endif //COMPUTERCLUB_EVENTCOME_H
