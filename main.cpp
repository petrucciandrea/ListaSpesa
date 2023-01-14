#include <iostream>

#include "Articolo.h"

int main() {
    auto *a = new Articolo("Mela", "Frutta", 3);

    std::cout << a->to_string() << std::endl;
    return 0;
}
