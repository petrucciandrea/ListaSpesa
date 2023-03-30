//
// Created by Andrea Petrucci on 14/01/23.
//

#ifndef LISTASPESA_ARTICOLO_H
#define LISTASPESA_ARTICOLO_H

#include <iostream>

using namespace std;

class Articolo {

public:


    Articolo(const string &nome, const string &categoria, int qnt);

    const string &getNome() const;

    void setNome(const string &nome);

    const string &getCategoria() const;

    void setCategoria(const string &categoria);

    int getQnt() const;

    void setQnt(int qnt);

    bool isStato() const;

    void setStato(bool stato);

    const string to_string() const;

    bool operator==(const string str) {
        return (str == nome);
    }

protected:
    string nome;
    string categoria;
    int qnt;
    bool stato = false;

};


#endif //LISTASPESA_ARTICOLO_H
