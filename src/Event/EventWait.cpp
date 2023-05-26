#include "EventWait.h"
#include "../Exception/EventException.h"

EventWait::EventWait(const Time &time, const string &client)
        : Event(time, EventType::WAIT, client) {}

void EventWait::handle(shared_ptr<ComputerClub> &club) {
    if (club->hasFreeTables()) {
        throw EventException(EventType::ERROR, "ICanWaitNoLonger");
    }

    club->takeQueue(getBody(), getTime());
}
