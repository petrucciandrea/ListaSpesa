//
// Created by Andrea Petrucci on 14/01/23.
//

#include "Articolo.h"

#include <utility>

/**
 * Costruttore
 * @param n nome
 * @param c categoria
 * @param q quantità
 */
Articolo::Articolo(string n, string c, int q) : nome(std::move(n)), categoria(std::move(c)), qnt(q) {}

/**
 * Getter
 * @return nome
 */
string &Articolo::getNome() {
    return nome;
}

/**
 * Setter
 * @param nome
 */
void Articolo::setNome(const string &n) {
    Articolo::nome = n;
}

/**
 * Getter
 * @return categoria
 */
string &Articolo::getCategoria() {
    return categoria;
}

/**
 * Setter
 * @param categoria
 */
void Articolo::setCategoria(const string &c) {
    Articolo::categoria = c;
}

/**
 * Getter
 * @return quantità
 */
int Articolo::getQnt() const {
    return qnt;
}

/**
 * Setter
 * @param qnt quantità
 */
void Articolo::setQnt(int q) {
    Articolo::qnt = q;
}

/**
 * Getter
 * @return stato
 */
bool Articolo::isStato() const {
    return stato;
}

/**
 * Setter
 * @param stato
 */
void Articolo::setStato(bool s) {
    Articolo::stato = s;
}

/**
 * Formattazione
 * @return stringa
 */
string Articolo::to_string() {
    return nome + " (" + categoria + ") qnt. " + std::to_string(qnt) + " [" + ((stato) ? "comprato" : "da comprare") + "]";
}
