#include <iostream>

#include "Articolo.h"
#include "Lista.h"

int main() {
    Articolo a = Articolo("Mela", "Frutta", 3);
    Articolo b = Articolo("Pera", "Frutta", 1);
    Articolo c = Articolo("Bistecca", "Carne", 5);
//    std::cout << a.to_string() << std::endl << b.to_string() << std::endl << c.to_string() << std::endl;

    Lista l = Lista("Lista1");
    l.inserisci(a);
    l.inserisci(b);
    l.inserisci(c);

    std::cout << l.to_string() << std::endl;
    l.compra(b);
    std::cout << l.to_string() << std::endl;

    return 0;
}
