#include "EventsHandler.h"

void EventsHandler::handle(const vector<Event> &events) {
    for (auto &item:events) {
        if (item.type == EventType::COME)
        {

        }
        cout << item << endl;
    }
}
