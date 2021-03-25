#include <iostream>
#include "Librarie.h"
#include "Caiet.h"
#include "Manual.h"

int main() {
    Librarie lib1("Carturesti");
    Manual man1(7, "mate", 8, 30);
    Manual man2(7, "mate", 3, 20);
    Caiet c1(80, "dictando", 10, 15);
    Caiet c2(160, "dictando", 4, 25);
    Caiet c3(80, "dictando", 5, 15);
    Caiet c4(160, "dictando", 9, 10);
    Caiet c5(160, "velin", 17, 5);
    Manual man3(7, "mate", 10, 20);

    std::cout<<"\nLibraria:";
    std::cout<<lib1;

    lib1.adauga(man1);
    lib1.adauga(man2);
    lib1.adauga(c1);
    lib1.adauga(c2);

    std::cout<<"\nLibraria dupa ce am adaugat produse:";
    std::cout<<lib1;

    lib1.adauga(c3); //modifica stoc c1
    lib1.adauga(c4);
    lib1.adauga(c5);
    lib1.adauga(man3); //modifica stoc man2

    std::cout<<"\nLibraria dupa ce am adaugat produse si am modificat stocul:";
    std::cout<<lib1;

    lib1.sterge(c3, 7);
    lib1.sterge(c2, 7);
    lib1.sterge(c3, 8);
    lib1.sterge(man1, 8);
    std::cout<<"\nLibraria dupa ce am sters produse:";
    std::cout<<lib1;

    std::cout<<"\nConstructor de copiere:";
    Manual man4 = man3;
    std::cout<<man4;

    std::cout<<"\nCel mai ieftin manual de matematica de clasa a 7a:";
    std::cout<<lib1.compara({man1, man2}, "mate", 7);
    std::cout<<"\nCel mai ieftin caiet de dictando:";
    std::cout<<lib1.compara({c2, c3, c1}, "dictando");
    return 0;
}
