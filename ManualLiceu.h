#ifndef LIBRARIE_MANUALLICEU_H
#define LIBRARIE_MANUALLICEU_H

#include "Manual.h"

class ManualLiceu : public Manual{
private:
    std::string profil;
public:
    ManualLiceu(const int &cls, std::string sub, int stoc, int pret, std::string prof);
    std::string getProfil();
    //int getPrice() override;
};

#endif //LIBRARIE_MANUALLICEU_H