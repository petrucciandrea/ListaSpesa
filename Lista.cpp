//
// Created by Andrea Petrucci on 14/01/23.
//

#include "Lista.h"

/**
 * Costruttore
 * @param t titolo
 */
Lista::Lista(const string &t) : titolo(t) {}

/**
 * Getter
 * @return
 */
const string &Lista::getTitolo() const {
    return titolo;
}

void Lista::setTitolo(const string &titolo) {
    Lista::titolo = titolo;
}

/**
 * Getter
 * @return articoli
 */
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

/**
 * Getter
 * @return numero articoli
 */
const int Lista::getNumArticoli() {
    return articoli.size();
}

/**
 * Getter
 * @return numero articoli da comprare
 */
const int Lista::getRimasti() {
    int n = 0;
    for (Articolo a: articoli)
        if (!a.isStato())
            n+= a.getQnt();
    return n;
}

/**
 * Formattazione
 * @return stringa
 */
string Lista::to_string() {
    string strOut = getTitolo() + ":\n";
//    for (auto it = articoli.begin(); it != articoli.end(); it++)
//        strOut += "    -" + it->to_string() + "\n";
    for (Articolo a: articoli)
        strOut += " -" + a.to_string() + "\n";
    return strOut;
}

bool Lista::compra(const Articolo &a) {
    auto it = find(articoli.begin(), articoli.end(), a.getNome());
    if (it != articoli.end()) {
        cout << a.getNome() << " spuntato dalla lista " << getTitolo();
        it->setStato(true);
    }
    return it->isStato();
}

bool Lista::cerca(const Articolo &a) {
    auto it = find(articoli.begin(), articoli.end(), a.getNome());
    return it != articoli.end();
}
