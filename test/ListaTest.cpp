//
// Created by Andrea Petrucci on 11/02/23.
//
#include "gtest/gtest.h"
#include "../Articolo.h"
#include "../Lista.h"

class ListaSuite : public ::testing::Test {
protected:
    Lista lista = Lista("Lunedì");
    Articolo a1 = Articolo("Mela", "Frutta", 2);
    Articolo a2 = Articolo("Pera", "Frutta", 3);
    Articolo a3 = Articolo("Cavolo", "Verdura", 5);

    virtual void SetUp(){
        lista.inserisci(a1);
        lista.inserisci(a2);
        lista.inserisci(a3);
    }
};

TEST_F(ListaSuite, Costructor){
    ASSERT_EQ("Lunedì", lista.getTitolo());
    ASSERT_EQ(10, lista.getRimasti());
}

TEST_F(ListaSuite, InOut) {
    lista.setTitolo("Martedì");
    ASSERT_EQ("Martedì", lista.getTitolo());
    ASSERT_EQ(10, lista.getRimasti());
    ASSERT_EQ(3, lista.getNumArticoli());
    lista.compra(a2);
    ASSERT_EQ(7, lista.getRimasti());
}

TEST_F(ListaSuite, toString) {
    ASSERT_EQ("Lunedì:\n -"+a1.to_string()+"\n -"+a2.to_string()+"\n -"+a3.to_string()+"\n", lista.to_string());
}
