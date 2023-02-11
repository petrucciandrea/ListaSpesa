//
// Created by Andrea Petrucci on 11/02/23.
//
#include "gtest/gtest.h"
#include "../Articolo.h"
#include "../Lista.h"
#include "../Utente.h"

TEST(Utente, Costructor){
    Utente u("Cbum");

    ASSERT_EQ("Cbum", u.getUsername());
}

TEST(Utente, TestName) {
    
}
