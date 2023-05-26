#include "EventHandler.h"
#include "../Exception/EventException.h"
#include <iostream>

EventHandler::EventHandler(const vector<shared_ptr<Event>> &events, const shared_ptr<ComputerClub> &computerClub)
        : events(events), computerClub(computerClub) {}

void EventHandler::handleEvents() {
    for (auto &event: events) {
        cout << *event << endl;
        try {
            event->handle(computerClub);
        } catch (const EventException &e) {
            cout << event->getTime() << " " << static_cast<int>(e.getType()) << " " << e.what() << endl;
        }
    }
}
