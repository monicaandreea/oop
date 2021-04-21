#include <iostream>
#include "Librarie.h"
#include "Caiet.h"
#include "Manual.h"
#include "ManualLiceu.h"
#include "ManualLucru.h"

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
    lib1.sterge(c2, 4);
    lib1.sterge(c3, 8);
    lib1.sterge(man1, 5);
    std::cout<<"\nLibraria dupa ce am sters produse:";
    std::cout<<lib1;

    std::cout<<"\nConstructor de copiere:";
    Manual man4 = man3;
    std::cout<<man4;

    std::cout<<"\nComparari, cel mai ieftin caiet de matematica de clasa a 7a: \n";
    std::cout<<lib1.compara("mate", 7);

    std::cout<<"\nManual de liceu:"<<"\n";
    ManualLiceu ro_l(10, "romana", 7, 15, "mate-info");
    std::cout<<ro_l;
    std::cout<<"Profil: "<<ro_l.getProfil()<<"\n";

    std::cout<<"\nManual de lucru pentru elevi:"<<"\n";
    ManualLucru man_l(10, "romana", 7, 15, 2, 0);
    std::cout<<man_l;
    std::cout<<"Dificulty: "<<man_l.getDificulty()<<"\nSolutions: ";
    if(man_l.getRez() == 1) std::cout<<"True";
    else std::cout<<"False";

    /*Manual m1(7, "ro", 5, 19);
    Manual m2(7, "ro", 6, 10);
    if(m1==m2) std::cout<<"\n\nunt egale.";
    else std::cout<<"\n\nsunt diferite."; */
    return 0;
}
