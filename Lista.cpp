//
// Created by Andrea Petrucci on 14/01/23.
//

#include "Lista.h"

Lista::Lista(const string &t) : titolo(t) {}

const string &Lista::getTitolo() const {
    return titolo;
}

void Lista::setTitolo(const string &titolo) {
    Lista::titolo = titolo;
}

const list<Articolo> &Lista::getArticoli() const {
    return articoli;
}

void Lista::inserisci(const Articolo &a) {
    articoli.push_back(a);
}

void Lista::elimina(const Articolo &a) {
    auto it = find(articoli.begin(), articoli.end(), a.getNome());
    if (it != articoli.end()) {
        articoli.erase(it);
    }
}

const int Lista::getNumArticoli() {
    return articoli.size();
}

const int Lista::getRimasti() {
    int n = 0;
//    for (auto it = articoli.begin(); it != articoli.end(); it++) {
//        if (!it->isStato())
//            n++;
//    }
    for (Articolo a: articoli)
        if (!a.isStato())
            n++;
    return n;
}

const string Lista::to_string() const {
    string strOut = getTitolo() + ":\n";
//    for (auto it = articoli.begin(); it != articoli.end(); it++)
//        strOut += "    -" + it->to_string() + "\n";
    for (Articolo a: articoli)
        strOut += "    -" + a.to_string() + "\n";
    return strOut;
}

bool Lista::compra(const Articolo &a) {
    auto it = find(articoli.begin(), articoli.end(), a.getNome());
    if (it != articoli.end()) {
        cout << "Hai acquistato " << a.getNome() << " dalla spesa: " << getTitolo() << "\n\n";
        it->setStato(true);
    }
    return it->isStato();
}
