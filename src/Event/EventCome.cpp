#include "EventCome.h"
#include "../Exception/EventException.h"

EventCome::EventCome(const Time &time, const string &body) : Event(time, EventType::COME, body) {}

void EventCome::handle(shared_ptr<ComputerClub> &club) {
    if (getTime() < club->getStart()) {
        throw EventException(EventType::ERROR, "NotOpenYet");
    }

    if (!club->hasClient(getBody())) {
        club->add(getBody());
    } else {
        throw EventException(EventType::ERROR, "YouShallNotPass");
    }
}
