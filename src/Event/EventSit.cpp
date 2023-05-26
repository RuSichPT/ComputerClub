#include "EventSit.h"

EventSit::EventSit(const Time &time, const string &client, int tableNumber)
        : Event(time, EventType::SIT, client), tableNumber(tableNumber) {}

void EventSit::handle(shared_ptr<ComputerClub> &club) {
    if (!club->hasClient(getClient())) {
        throw runtime_error("ClientUnknown");
    }

    club->takeTable(getClient(), getTime(), tableNumber);
}
