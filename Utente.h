//
// Created by Andrea Petrucci on 14/01/23.
//

#ifndef LISTASPESA_UTENTE_H
#define LISTASPESA_UTENTE_H

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include <algorithm>

#include "Lista.h"

class Utente : public Subject {
public:
    explicit Utente(string u);

    string &getUsername();

    void setUsername(const string &username);

    virtual void notify() override;

    virtual void subscribe(Observer *o) override;

    virtual void unsubscribe(Observer *o) override;

    void addLista(Lista l);

    void removeLista(const string &t);

    void aggiungiArticolo(const string &t, const Articolo &a);

    void removeArticolo(const string &t, const Articolo &a);

    string to_string();

    void compra(const Articolo &a);

    unsigned long getNumListe();

    int getRimasti(const string &t);

    virtual ~Utente() = default;

    bool operator==(const string& s) {
        return (s == username);
    }

protected:
    string username;
    list<Lista> liste;
    list<Observer *> observer;
};


#endif //LISTASPESA_UTENTE_H
