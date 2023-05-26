#ifndef COMPUTERCLUB_EVENTWAIT_H
#define COMPUTERCLUB_EVENTWAIT_H


#include "Event.h"

class EventWait : public Event {
public:

    EventWait(const Time &time, const string &client);

    void handle(shared_ptr<ComputerClub> &club) override;
};


#endif //COMPUTERCLUB_EVENTWAIT_H
