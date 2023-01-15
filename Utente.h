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
    explicit Utente(const string &u);

    const string &getUsername() const;

    void setUsername(const string &username);

    const list<Lista> &getLista() const;

    void setLista(const list<Lista> &lista);

    virtual void notify() override;

    virtual void subscribe(Observer *o) override;

    virtual void unsubscribe(Observer *o) override;

    void addLista(const Lista &l);

    void removeLista(const string &l);

    void aggiungiArticolo(const string &t, const Articolo &a);

    const string to_string() const;

    void compra(const Articolo &a);

    const int getNumListe();

    const int rimasti(const string &t);

    virtual ~Utente() = default;

    bool operator==(const string s) {
        return (s == username);
    }

protected:
    string username;
    list<Lista> lista;
    list<Observer *> observer;
};


#endif //LISTASPESA_UTENTE_H
