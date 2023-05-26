#include "EventLeave.h"

EventLeave::EventLeave(const Time &time, const string &client)
        : Event(time, EventType::LEAVE, client) {}

void EventLeave::handle(shared_ptr<ComputerClub> &club) {
    club->remove(getClient());
    club->releaseTable(getClient(), getTime());
}
