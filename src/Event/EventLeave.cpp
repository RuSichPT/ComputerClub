#include "EventLeave.h"
#include "../Exception/EventException.h"

EventLeave::EventLeave(const Time &time, const string &client)
        : Event(time, EventType::LEAVE, client) {}

void EventLeave::handle(shared_ptr<ComputerClub> &club) {
    club->remove(getBody());
    club->releaseTable(getBody(), getTime());
}
