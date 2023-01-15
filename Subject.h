//
// Created by Andrea Petrucci on 14/01/23.
//

#ifndef LISTASPESA_SUBJECT_H
#define LISTASPESA_SUBJECT_H

#include "Observer.h"

class Subject {
public:

    virtual void subscribe(Observer *o) = 0;

    virtual void unsubscribe(Observer *o) = 0;

    virtual void notify() = 0;

    virtual ~Subject() {};
};

#endif //LISTASPESA_SUBJECT_H
