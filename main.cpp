#include <iostream>

#include "Articolo.h"
#include "Lista.h"
#include "Utente.h"
#include "Lista.h"
#include "ListaNotifier.h"

int main() {
    auto* u1=new Utente("Arnold");
    auto* u2=new Utente("Ronnie");

    auto* ln1=new ListaNotifier(*u1);
    auto* ln2=new ListaNotifier(*u2);

    Articolo a1("Avena", "Carboidrati", 3);
    Articolo a2("Olio", "Grassi", 1);
    Articolo a3("Pollo", "Proteine", 1);
    Articolo a4("Uova", "Proteine", 1);

    Lista s1("Lunedì");
    Lista s2("Martedì");

    s1.inserisci(a1);
    s1.inserisci(a2);
    s1.inserisci(a4);

    s2.inserisci(a1);
    s2.inserisci(a2);
    s2.inserisci(a3);

    cout<<s1.cerca(a1)<<endl<<s1.cerca(a3);

    u1->addLista(s1);

    u2->addLista(s1);
    u2->addLista(s2);

    cout << u2->to_string();
    cout << u1->to_string();

    u1->compra(a1);
    u1->compra(a4);

    cout << endl;

    u2->compra(a1);
    u2->compra(a2);
    u2->compra(a3);

    cout << u2->to_string();
    cout << u1->to_string();

    delete ln1;
    delete ln2;
    delete u1;
    delete u2;
}
