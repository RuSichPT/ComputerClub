#ifndef COMPUTERCLUB_APPLICATION_H
#define COMPUTERCLUB_APPLICATION_H


#include <memory>
#include "../LoadedData/LoadedData.h"
#include "../ComputerClub/ComputerClub.h"
#include "../EventHandler/EventHandler.h"

class Application {
public:
    explicit Application(const string &path);

    void run();

private:
    LoadedData data;
    shared_ptr<ComputerClub> computerClub;
    unique_ptr<EventHandler> eventHandler;
};


#endif //COMPUTERCLUB_APPLICATION_H
