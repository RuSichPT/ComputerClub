#ifndef COMPUTERCLUB_EVENTSHANDLER_H
#define COMPUTERCLUB_EVENTSHANDLER_H

#include <vector>
#include "../Event/Events.h"
#include <iostream>

using namespace std;

class EventsHandler {
public:
    void handle(const vector<Event> &events);
};


#endif //COMPUTERCLUB_EVENTSHANDLER_H
