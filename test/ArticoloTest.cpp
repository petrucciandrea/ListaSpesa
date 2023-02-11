//
// Created by Andrea Petrucci on 09/02/23.
//

#include "gtest/gtest.h"
#include "../Articolo.h"

TEST(Articolo, Costructor){
    Articolo a("Mela", "Frutta", 1);
    ASSERT_EQ("Mela", a.getNome());
    ASSERT_EQ("Frutta", a.getCategoria());
    ASSERT_EQ(1, a.getQnt());
    ASSERT_FALSE(a.isStato());
}

TEST(Articolo, Setter) {
    Articolo a("Mela", "Frutta", 1);

    a.setNome("Cavolo");
    ASSERT_EQ("Cavolo", a.getNome());

    a.setCategoria("Verdura");
    ASSERT_EQ("Verdura", a.getCategoria());

    a.setQnt(4);
    ASSERT_EQ(4, a.getQnt());

    a.setStato(true);
    ASSERT_TRUE(a.isStato());
}

TEST(Articolo, toString) {
    Articolo a("Mela", "Frutta", 1);
    ASSERT_EQ("Mela (Frutta) qnt. 1 [da comprare]", a.to_string());
}
