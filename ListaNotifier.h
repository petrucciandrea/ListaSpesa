//
// Created by Andrea Petrucci on 09/02/23.
//

#ifndef LISTASPESA_LISTANOTIFIER_H
#define LISTASPESA_LISTANOTIFIER_H

#include "Observer.h"
#include "Lista.h"
#include "Utente.h"

#include <iostream>
#include <string>
#include <algorithm>

class ListaNotifier : public Observer {
public:
    explicit ListaNotifier(Utente &u) : utente(&u) {
        this->utente->subscribe(this);
    }

    void update() override {
        utente->to_string();
    }

private:
    Utente *utente;
};

#endif //LISTASPESA_LISTANOTIFIER_H
