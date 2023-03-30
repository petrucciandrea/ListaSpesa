//
// Created by Andrea Petrucci on 14/01/23.
//

#include "Utente.h"

#include <utility>

Utente::Utente(string u) : username(std::move(u)) {}

string &Utente::getUsername() {
    return username;
}

void Utente::setUsername(const string &u) {
    Utente::username = u;
}

void Utente::notify() {
    for (auto & it : observer)
        it->update();
}

void Utente::subscribe(Observer *o) {
    observer.push_back(o);
}

void Utente::unsubscribe(Observer *o) {
    observer.remove(o);
}

void Utente::addLista(Lista l) {
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

string Utente::to_string() {
    string strOut = "\n" + username + ":\n";
    for (Lista l: liste)
        strOut += "  " + l.to_string() + "\n";
    return strOut;
}

void Utente::compra(const Articolo &a) {
    for (auto & it : liste)
        if(it.compra(a))
            cout << " da " << username << endl;
    notify();
}

unsigned long Utente::getNumListe() {
    return liste.size();
}

int Utente::getRimasti(const string &t) {
    auto it = find(liste.begin(), liste.end(), t);
    return (it != liste.end()) ? it->getRimasti() : 0;
}
