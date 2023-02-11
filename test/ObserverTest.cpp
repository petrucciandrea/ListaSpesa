//
// Created by Andrea Petrucci on 11/02/23.
//

#include "gtest/gtest.h"
#include "../Articolo.h"
#include "../Lista.h"
#include "../Utente.h"

class ObserverSuite : public ::testing::Test, public Observer {
protected:
    Utente* utente = new Utente("Cbum");
    Lista lista = Lista("Lunedì");
    Articolo articolo = Articolo("Pollo", "Carne", 5);
    bool ctr = false;

    void update() override {
        ctr=true;
    }

    virtual void SetUp(){
        lista.inserisci(articolo);
        this->utente->subscribe(this);
    }

    virtual void TearDown(){
        this->utente->unsubscribe(this);
    }
};

TEST_F(ObserverSuite, Costructor){
    utente->addLista(lista);
    utente->compra(articolo);
    ASSERT_TRUE(ctr);
}
