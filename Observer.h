//
// Created by Andrea Petrucci on 14/01/23.
//

#ifndef LISTASPESA_OBSERVER_H
#define LISTASPESA_OBSERVER_H

#include <string>

class Observer {

public:
    virtual void update() = 0;

    virtual ~Observer() {};
};

#endif //LISTASPESA_OBSERVER_H
