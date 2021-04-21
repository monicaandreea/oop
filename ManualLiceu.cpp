
#include "ManualLiceu.h"

ManualLiceu::ManualLiceu(const int &cls, std::string sub, int stoc, int pret, std::string prof)
        : Manual(cls, sub, stoc, pret), profil(prof){}

std::string ManualLiceu::getProfil() {
    return profil;
}

/*int ManualLiceu::getPrice() {
    return Manual::getPrice() + 100;
} */

