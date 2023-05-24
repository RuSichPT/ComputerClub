#ifndef COMPUTERCLUB_EVENTTYPE_H
#define COMPUTERCLUB_EVENTTYPE_H

enum class EventType {
    NONE,
    COME,
    SIT,
    WAIT,
    LEAVE,
    END_DAY_OR_LEAVE = 11,
    QUEUE,
    ERROR,

};
#endif //COMPUTERCLUB_EVENTTYPE_H
