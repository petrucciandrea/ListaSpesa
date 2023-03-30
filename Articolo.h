//
// Created by Andrea Petrucci on 14/01/23.
//

#ifndef LISTASPESA_ARTICOLO_H
#define LISTASPESA_ARTICOLO_H

#include <iostream>

using namespace std;

class Articolo {

public:

    Articolo(string nome, string categoria, int qnt);

    string &getNome();

    void setNome(const string &nome);

    string &getCategoria();

    void setCategoria(const string &categoria);

    int getQnt() const;

    void setQnt(int qnt);

    bool isStato() const;

    void setStato(bool stato);

    string to_string();

    bool operator==(const string& str) {
        return (str == nome);
    }

protected:
    string nome;
    string categoria;
    int qnt;
    bool stato = false;

};


#endif //LISTASPESA_ARTICOLO_H
