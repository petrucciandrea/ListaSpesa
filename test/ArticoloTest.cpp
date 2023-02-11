//
// Created by Andrea Petrucci on 09/02/23.
//

#include "gtest/gtest.h"
#include "../Articolo.h"

class ArticoloSuite : public ::testing::Test {
protected:
    Articolo articolo = Articolo("Mela", "Frutta", 2);
};

TEST_F(ArticoloSuite, Costructor){
    ASSERT_EQ("Mela", articolo.getNome());
    ASSERT_EQ("Frutta", articolo.getCategoria());
    ASSERT_EQ(2, articolo.getQnt());
    ASSERT_FALSE(articolo.isStato());
}

TEST_F(ArticoloSuite, Setter) {
    articolo.setNome("Cavolo");
    articolo.setCategoria("Verdura");
    articolo.setQnt(4);
    articolo.setStato(true);
    ASSERT_EQ("Cavolo", articolo.getNome());
    ASSERT_EQ("Verdura", articolo.getCategoria());
    ASSERT_EQ(4, articolo.getQnt());
    ASSERT_TRUE(articolo.isStato());
}

TEST_F(ArticoloSuite, toString) {
    ASSERT_EQ("Mela (Frutta) qnt. 2 [da comprare]", articolo.to_string());
}
