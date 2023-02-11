//
// Created by Andrea Petrucci on 11/02/23.
//
#include "gtest/gtest.h"
#include "../Articolo.h"
#include "../Lista.h"
#include "../Utente.h"

class UtenteSuite : public ::testing::Test {
protected:
    Utente utente = Utente("Cbum");
    Lista lista1 = Lista("Lunedì");
    Lista lista2 = Lista("Martedì");
    Articolo a1 = Articolo("Mela", "Frutta", 2);
    Articolo a2 = Articolo("Pera", "Frutta", 3);
    Articolo a3 = Articolo("Cavolo", "Verdura", 5);
    Articolo a4 = Articolo("Pollo", "CArne", 5);
    Articolo a5 = Articolo("Bresaola", "Affettato", 5);

    virtual void SetUp(){
        lista1.inserisci(a1);
        lista1.inserisci(a2);
        lista1.inserisci(a3);
        lista2.inserisci(a4);
        lista2.inserisci(a5);
        utente.addLista(lista1);
        utente.addLista(lista2);
    }
};

TEST_F(UtenteSuite, Costructor){
    ASSERT_EQ("Cbum", utente.getUsername());
    ASSERT_EQ(2, utente.getNumListe());
    ASSERT_EQ(lista1.getRimasti(), utente.getRimasti("Lunedì"));
    ASSERT_EQ(lista2.getRimasti(), utente.getRimasti("Martedì"));
}

TEST_F(UtenteSuite, Setter){
    utente.setUsername("Cris");
    utente.removeLista("Martedì");
    Articolo a("Orata", "Pesce", 2);
    utente.aggiungiArticolo("Lunedì", a);
    ASSERT_EQ("Cris", utente.getUsername());
    ASSERT_EQ(1, utente.getNumListe());
    ASSERT_EQ(lista1.getRimasti()+2, utente.getRimasti("Lunedì"));
    utente.removeArticolo("Lunedì", a);
    ASSERT_EQ(lista1.getRimasti(), utente.getRimasti("Lunedì"));
}

TEST_F(UtenteSuite, toString){
    ASSERT_EQ("\nCbum:\n  "+lista1.to_string()+"\n  "+lista2.to_string()+"\n", utente.to_string());
}