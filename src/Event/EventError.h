#ifndef COMPUTERCLUB_EVENTERROR_H
#define COMPUTERCLUB_EVENTERROR_H


#include "Event.h"

class EventError : Event {
public:
    EventError(const Time &time, const string &client);

private:
    void handle(shared_ptr<ComputerClub> &club) override;
};


#endif //COMPUTERCLUB_EVENTERROR_H
