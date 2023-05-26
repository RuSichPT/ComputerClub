#include "EventError.h"

EventError::EventError(const Time &time, const string &client) : Event(time, EventType::ERROR, client) {}

void EventError::handle(shared_ptr<ComputerClub> &club) {

}
