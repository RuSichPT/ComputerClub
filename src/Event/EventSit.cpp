#include "EventSit.h"
#include "../Exception/EventException.h"

EventSit::EventSit(const Time &time, const string &client, int tableNumber)
        : Event(time, EventType::SIT, client), tableNumber(tableNumber) {}

void EventSit::handle(shared_ptr<ComputerClub> &club) {
    if (!club->hasClient(getBody())) {
        throw EventException(EventType::ERROR, "ClientUnknown");
    }

    club->takeTable(getBody(), getTime(), tableNumber);
}

string EventSit::toString() const {
    return Event::toString() + " " + to_string(tableNumber);
}

