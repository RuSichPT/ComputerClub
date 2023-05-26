#ifndef COMPUTERCLUB_EVENTSIT_H
#define COMPUTERCLUB_EVENTSIT_H

#include <ostream>
#include "Event.h"

class EventSit : public Event {
public:
    EventSit(const Time &time, const string &client, int tableNumber);

    void handle(shared_ptr<ComputerClub> &club) override;

    string toString() const override;

private:
    int tableNumber;
};


#endif //COMPUTERCLUB_EVENTSIT_H
