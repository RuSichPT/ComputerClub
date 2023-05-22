#include "EventsHandler.h"

void EventsHandler::handle(const vector<Event> &events) {
    for (auto &item:events) {
        cout << item << endl;
    }
}
