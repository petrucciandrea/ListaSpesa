//
// Created by Andrea Petrucci on 14/01/23.
//

#include "Lista.h"

#include <utility>

/**
 * Costruttore
 * @param t titolo
 */
Lista::Lista(string t) : titolo(std::move(t)) {}

/**
 * Getter
 * @return
 */
string &Lista::getTitolo() {
    return titolo;
}

void Lista::setTitolo(const string &t) {
    Lista::titolo = t;
}

void Lista::inserisci(const Articolo &a) {
    articoli.push_back(a);
}

void Lista::elimina(Articolo a) {
    auto it = find(articoli.begin(), articoli.end(), a.getNome());
    if (it != articoli.end()) {
        articoli.erase(it);
    }
}

/**
 * Getter
 * @return numero articoli
 */
unsigned long Lista::getNumArticoli() {
    return articoli.size();
}

/**
 * Getter
 * @return numero articoli da comprare
 */
int Lista::getRimasti() {
    int n = 0;
    for (const Articolo& a: articoli)
        if (!a.isStato())
            n++;
    return n;
}

/**
 * Formattazione
 * @return stringa
 */
string Lista::to_string() {
    string strOut = getTitolo() + ":\n";
    for (Articolo a: articoli)
        strOut += " -" + a.to_string() + "\n";
    return strOut;
}

/**
 * Compra l'articolo passato
 * @param a
 * @return
 */
bool Lista::compra(Articolo a) {
    auto it = find(articoli.begin(), articoli.end(), a.getNome());
    if (it != articoli.end()) {
        cout << a.getNome() << " spuntato dalla lista " << getTitolo();
        it->setStato(true);
    }
    return it->isStato();
}

/**
 * Cerca se l'articolo passato è presente o meno
 * @param a
 * @return
 */
bool Lista::cerca(Articolo a) {
    auto it = find(articoli.begin(), articoli.end(), a.getNome());
    return it != articoli.end();
}
