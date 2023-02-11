//
// Created by Andrea Petrucci on 11/02/23.
//
#include "gtest/gtest.h"
#include "../Articolo.h"
#include "../Lista.h"


TEST(ListaSuite, Costructor){
    Lista l("Lunedì");
    ASSERT_EQ("Lunedì", l.getTitolo());
    ASSERT_EQ(0, l.getRimasti());
}

TEST(Lista, InOut) {
    Lista l("Lunedì");

    l.setTitolo("Martedì");
    ASSERT_EQ("Martedì", l.getTitolo());

    Articolo a1("Mela", "Frutta", 2);
    Articolo a2("Pera", "Frutta", 3);
    Articolo a3("Cavolo", "Verdura", 5);

    l.inserisci(a1);
    l.inserisci(a2);
    l.inserisci(a3);

    ASSERT_EQ(10, l.getRimasti());
    ASSERT_EQ(3, l.getNumArticoli());

    l.compra(a2);

    ASSERT_EQ(7, l.getRimasti());
}

TEST(Lista, toString) {
    Lista l("Lunedì");
    Articolo a1("Mela", "Frutta", 2);
    Articolo a2("Pera", "Frutta", 3);
    l.inserisci(a1);
    l.inserisci(a2);
    ASSERT_EQ("Lunedì:\n -"+a1.to_string()+"\n -"+a2.to_string()+"\n", l.to_string());
}
