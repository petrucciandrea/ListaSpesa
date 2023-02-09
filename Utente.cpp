//
// Created by Andrea Petrucci on 14/01/23.
//

#include "Utente.h"

Utente::Utente(const string &u) : username(u) {}

const string &Utente::getUsername() const {
    return username;
}

void Utente::setUsername(const string &username) {
    Utente::username = username;
}

const list<Lista> &Utente::getLista() const {
    return lista;
}

void Utente::setLista(const list<Lista> &lista) {
    Utente::lista = lista;
}


void Utente::notify() {
    for (auto it = observer.begin(); it != observer.end(); it++) {
        (*it)->update();
    }
}

void Utente::subscribe(Observer *o) {
    observer.push_back(o);
}

void Utente::unsubscribe(Observer *o) {
    observer.remove(o);
}

void Utente::addLista(const Lista &l) {
    auto it = find(lista.begin(), lista.end(), l.getTitolo());
    if (it == lista.end()) {
        lista.push_back(l);
        notify();
    } else
        cout << "Lista già presente" << endl;
}

void Utente::removeLista(const string &t) {
    auto it = find(lista.begin(), lista.end(), t);
    if (it != lista.end()) {
        lista.erase(it);
        notify();
    }
}

void Utente::aggiungiArticolo(const string &t, const Articolo &a) {
    auto it = find(lista.begin(), lista.end(), t);
    if (it != lista.end()) {
        it->inserisci(a);
        notify();
    }
}

const string Utente::to_string() const {
    string strOut = "\n" + username + ":\n";
//    for (auto it = lista.begin(); it != lista.end(); it++)
//        cout << "nome della lista :" << it->getTitolo() << endl << it->to_string() << "Articoli totali da acquistare :" << it->getRimasti() << " nella lista " << it->getTitolo() << endl;
    for (Lista l: lista)
        strOut += "  " + l.to_string() + "\n";
    return strOut;
}

void Utente::compra(const Articolo &a) {
    for (auto it = lista.begin(); it != lista.end(); it++) {
        cout << username << " ha ";
        it->compra(a);
    }
    notify();
}

const int Utente::getNumListe() {
    return lista.size();
}

const int Utente::rimasti(const string &t) {
    int n = 0;
    auto it = find(lista.begin(), lista.end(), t);
    if (it != lista.end()) {
        n = it->getRimasti();
    }
    return n;
}
