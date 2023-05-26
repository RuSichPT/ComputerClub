#include "EventHandler.h"
#include <iostream>

EventHandler::EventHandler(const vector<shared_ptr<Event>> &events, const shared_ptr<ComputerClub> &computerClub)
        : events(events), computerClub(computerClub) {}

void EventHandler::handleEvents() {
    for (auto &event: events) {
        cout << *event << endl;
        try {
            event->handle(computerClub);
        } catch (const exception &e) {
            cout << event->getTime() << " " << static_cast<int>(event->getType())<< " " << e.what() << endl;
        }
    }
}
