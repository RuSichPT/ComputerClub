#ifndef COMPUTERCLUB_EVENTHANDLER_H
#define COMPUTERCLUB_EVENTHANDLER_H

#include <vector>
#include <memory>
#include "../Event/Event.h"
#include "../ComputerClub/ComputerClub.h"


using namespace std;

class EventHandler {
public:
    EventHandler(const vector<shared_ptr<Event>> &events, const shared_ptr<ComputerClub> &computerClub);

public:
    void handleEvents();

private:
    vector<shared_ptr<Event>> events;
    shared_ptr<ComputerClub> computerClub;
};


#endif //COMPUTERCLUB_EVENTHANDLER_H
