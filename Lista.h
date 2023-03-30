//
// Created by Andrea Petrucci on 14/01/23.
//

#ifndef LISTASPESA_LISTA_H
#define LISTASPESA_LISTA_H

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <memory>

#include "Articolo.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

class Lista {
public:
    explicit Lista(const string &t);

    const string &getTitolo() const;

    void setTitolo(const string &titolo);

    const list<Articolo> &getArticoli() const;

    void inserisci(const Articolo &a);

    void elimina(const Articolo &a);

    bool compra(const Articolo &a);

    bool cerca(const Articolo &a);

    const int getNumArticoli();

    const int getRimasti();

    string to_string();

    bool operator==(const string str) {
        return (str == titolo);
    }

protected:
    string titolo;
    list<Articolo> articoli;
};


#endif //LISTASPESA_LISTA_H
