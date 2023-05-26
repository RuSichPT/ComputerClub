#include "EventCome.h"
#include "EventError.h"

EventCome::EventCome(const Time &time, const string &client) : Event(time, EventType::COME, client) {}

void EventCome::handle(shared_ptr<ComputerClub> &club) {
    if (getTime() < club->getStart()) {
        throw EventError(getTime(),"NotOpenYet");
    }

    if (!club->hasClient(getClient())) {
        club->add(getClient());
    } else {
        throw runtime_error("YouShallNotPass");
    }
}
