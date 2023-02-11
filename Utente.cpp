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
    return liste;
}

void Utente::setLista(const list<Lista> &liste) {
    Utente::liste = liste;
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
    auto it = find(liste.begin(), liste.end(), l.getTitolo());
    if (it == liste.end()) {
        liste.push_back(l);
        notify();
    } else
        cout << "Lista già presente" << endl;
}

void Utente::removeLista(const string &t) {
    auto it = find(liste.begin(), liste.end(), t);
    if (it != liste.end()) {
        liste.erase(it);
        notify();
    }
}

void Utente::aggiungiArticolo(const string &t, const Articolo &a) {
    auto it = find(liste.begin(), liste.end(), t);
    if (it != liste.end()) {
        it->inserisci(a);
        notify();
    }
}

void Utente::removeArticolo(const string &t, const Articolo &a) {
    auto it = find(liste.begin(), liste.end(), t);
    if (it != liste.end()) {
        it->elimina(a);
        notify();
    }
}

const string Utente::to_string() const {
    string strOut = "\n" + username + ":\n";
//    for (auto it = liste.begin(); it != liste.end(); it++)
//        cout << "nome della liste :" << it->getTitolo() << endl << it->to_string() << "Articoli totali da acquistare :" << it->getRimasti() << " nella liste " << it->getTitolo() << endl;
    for (Lista l: liste)
        strOut += "  " + l.to_string() + "\n";
    return strOut;
}

void Utente::compra(const Articolo &a) {
    for (auto it = liste.begin(); it != liste.end(); it++) {
        if(it->compra(a))
            cout << " da " << username << endl;
    }
    notify();
}

const int Utente::getNumListe() {
    return liste.size();
}

const int Utente::getRimasti(const string &t) {
    int n = 0;
    auto it = find(liste.begin(), liste.end(), t);
    if (it != liste.end()) {
        n = it->getRimasti();
    }
    return n;
}
