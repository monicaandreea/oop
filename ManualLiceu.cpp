
#include "ManualLiceu.h"


std::string ManualLiceu::getProfil() {
    return profil;
}

int ManualLiceu::getPrice() {
    return Manual::getPrice() + 10;
}

ManualLiceu::ManualLiceu(const int &cls, std::string sub, int stoc, int pret)
        : Manual(cls, sub, stoc, pret){}


std::unique_ptr <Manual> ManualLiceu::clone(){
    return std::make_unique <ManualLiceu>(*this);
}

ManualLiceu::ManualLiceu(const int &cls, std::string sub, int stoc, int pret, std::string prof)
        : Manual(cls, sub, stoc, pret), profil(prof){}
