#include "EventWait.h"

EventWait::EventWait(const Time &time, const string &client)
        : Event(time, EventType::WAIT, client) {}

void EventWait::handle(shared_ptr<ComputerClub> &club) {
    if (club->hasFreeTables()) {
        throw runtime_error("ICanWaitNoLonger");
    }

    club->takeQueue(getClient(), getTime());
}
