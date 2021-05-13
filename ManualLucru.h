#ifndef LIBRARIE_MANUALLUCRU_H
#define LIBRARIE_MANUALLUCRU_H

#include "Manual.h"

class ManualLucru : public Manual{
private:
    int dificultate; //1- avansat, 2-mediu, 3-incepator
    bool rezolvari; //0-nu are rezolvari, 1-are rezolvari
public:
    ManualLucru(const int &cls, std::string sub, int stoc, int pret);
    ManualLucru(const int &cls, std::string sub, int stoc, int pret, int dif, int rez);
    int getDificulty();
    bool getRez();
    int getPrice() override;
    std::unique_ptr <Manual> clone() override;
};

#endif //LIBRARIE_MANUALLUCRU_H
