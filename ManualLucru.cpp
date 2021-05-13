
#include "ManualLucru.h"

bool ManualLucru::getRez() {
    return rezolvari;
}

int ManualLucru::getDificulty() {
    return dificultate;
}

int ManualLucru::getPrice() {
    return Manual::getPrice() -5; //reducere?
}

ManualLucru::ManualLucru(const int &cls, std::string sub, int stoc, int pret)
        : Manual(cls, sub, stoc, pret){}


std::unique_ptr <Manual> ManualLucru::clone(){
    return std::make_unique <ManualLucru>(*this);
}

ManualLucru::ManualLucru(const int &cls, std::string sub, int stoc, int pret, int dif, int rez)
        : Manual(cls, sub, stoc, pret), dificultate(dif), rezolvari(rez){}
