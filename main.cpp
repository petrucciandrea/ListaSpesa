#include <iostream>

#include "Articolo.h"
#include "Lista.h"
#include "Utente.h"

int main() {
    Articolo a = Articolo("Mela", "Frutta", 3);
    Articolo b = Articolo("Pera", "Frutta", 1);
    Articolo c = Articolo("Bistecca", "Carne", 5);

    Lista l = Lista("Lista1");
    l.inserisci(a);
    l.inserisci(b);
    l.inserisci(c);

//    std::cout << l.to_string() << std::endl;
//    l.compra(b);
//    std::cout << l.to_string() << std::endl;

    Utente u1 = Utente("mario.rossi");
    u1.addLista(l);

    cout << u1.to_string();
    u1.compra(b);
    cout << u1.to_string();
    cout << u1.rimasti("Lista1") << " articoli rimasti\n";

    return 0;
}
