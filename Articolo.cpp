//
// Created by Andrea Petrucci on 14/01/23.
//

#include "Articolo.h"

Articolo::Articolo(const string &n, const string &c, int q) : nome(n), categoria(c), qnt(q) {}

const string &Articolo::getNome() const {
    return nome;
}

void Articolo::setNome(const string &nome) {
    Articolo::nome = nome;
}

const string &Articolo::getCategoria() const {
    return categoria;
}

void Articolo::setCategoria(const string &categoria) {
    Articolo::categoria = categoria;
}

int Articolo::getQnt() const {
    return qnt;
}

void Articolo::setQnt(int qnt) {
    Articolo::qnt = qnt;
}

bool Articolo::isStato() const {
    return stato;
}

void Articolo::setStato(bool stato) {
    Articolo::stato = stato;
}

const string Articolo::to_string() const {
    return nome + " (" + categoria + ") qnt. " + std::to_string(qnt) + " [" + ((stato) ? "comprato" : "da comprare") + "]";
}
