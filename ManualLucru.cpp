
#include "ManualLucru.h"

ManualLucru::ManualLucru(const int &cls, std::string sub, int stoc, int pret, int dif, int rez)
    : Manual(cls, sub, stoc, pret), dificultate(dif), rezolvari(rez){}

bool ManualLucru::getRez() {
    return rezolvari;
}

int ManualLucru::getDificulty() {
    return dificultate;
}
