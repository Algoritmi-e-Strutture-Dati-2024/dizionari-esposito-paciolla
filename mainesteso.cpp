#include <iostream>
#include "DizionarioEsteso.h"

int main() {
    DizionarioEsteso dizio;

    dizio.inserisci("apple", "frutta");
    dizio.inserisci("car", "veicolo");
    dizio.inserisci("book", "oggetto");

    std::cout << "Valore per 'apple': " << dizio.recupera("apple") << "\n";
    std::cout << "Valore per 'car': " << dizio.recupera("car") << "\n";
    std::cout << "Valore per 'pen': " << dizio.recupera("pen") << "\n";

    dizio.stampa();

    dizio.cancella("car");
    std::cout << "Valore per 'car' dopo cancellazione: " << dizio.recupera("car") << "\n";

    dizio.stampa();

    return 0;
}
