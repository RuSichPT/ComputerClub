#include "Application.h"
#include <iostream>

Application::Application(const string &path) : data(path) {
    computerClub = make_shared<ComputerClub>(data.getStart(), data.getEnd(), data.getNumTables(), data.getHourCost());
    eventHandler = make_unique<EventHandler>(data.getEvents(), computerClub);
}

void Application::run() {
    cout << computerClub->getStart() << endl;
    eventHandler->handleEvents();
    cout << computerClub->getEnd() << endl;
    computerClub->printProfit();
}
