#include<iostream>
#include "Librarie.h"
#include "stoc_insuficient.h"
#include "produs_inexistent.h"
#include <utility>
#include <algorithm>

Librarie::Librarie(const std::string &nume): name( nume ){}

Librarie::~Librarie(){
    //std::cout<<"\ns-a apelat destructorul lib"<<std::endl;
}


void Librarie::setName(std::string a){
    name = a;
}

std::string Librarie::getName(){
    return name;
}

void Librarie::adauga(Caiet &caiet){  ///verifica daca produsul exista deja, iar daca exista ii modifica stocul, daca nu, il adauga la librarie
    int ok = 1;
    for(auto &c : this->caiete)
        if( c == caiet)
        {
            c.setStock(c.getStock() + caiet.getStock());
            ok = 0;
            break;
        }
    if(ok == 1) caiete.push_back(caiet);
}

void Librarie::sterge(Caiet &caiet, int cantitate){ ///verifica daca cantitatea ceruta este mai mare decat stocul, iar daca stocul este 0, sterge produsul
    for(auto &c : this->caiete)
        if( c == caiet )
        {
            try{
                if(c.getStock() >= cantitate)
                    c.setStock( c.getStock() - cantitate );
                else{throw stoc_insuficient(c.getStock(), cantitate );}
            }

            catch(int num){
                std::cout<<"Atentie! Cantitatea ceruta este mai mare decat stocul.\n";
                std::cout<<"Stocul curent este: "<<num;
            }
            if(c.getStock() <= 0)
                caiete.erase(remove(caiete.begin(), caiete.end(), caiet));
            break;
        }
}

void Librarie::adauga(ManualLucru &man){
    int ok = 1;
    for(auto &m : this->manuale)
        if( m == man && m.getRez()==man.getRez() && m.getDificulty()==man.getDificulty())
        {
            m.setStock(m.getStock() + man.getStock());
            ok = 0;
            break;
        }
    if(ok == 1) manuale.push_back(man);
}

void Librarie::sterge(ManualLucru &man, int cantitate){
    for(auto &m : this->manuale)
        if( m == man )
        {
            try{
                if(m.getStock() >= cantitate)
                    m.setStock( m.getStock() - cantitate );
                else{throw stoc_insuficient(m.getStock(), cantitate );}
            }

            catch(int num){
                std::cout<<"Atentie! Cantitatea ceruta este mai mare decat stocul.\n";
                std::cout<<"Stocul curent este: "<<num;
            }

            if(m.getStock() <= 0)
                manuale.erase(remove(manuale.begin(), manuale.end(), man));
            break;
        }
}

void Librarie::adauga(ManualLiceu &man){
    int ok = 1;
    for(auto &m : this->manualeliceu)
        if( m == man && m.getProfil() == man.getProfil())
        {
            m.setStock(m.getStock() + man.getStock());
            ok = 0;
            break;
        }
    if(ok == 1) manualeliceu.push_back(man);
}

void Librarie::sterge(ManualLiceu &man, int cantitate){
    for(auto &m : this->manualeliceu)
        if( m == man )
        {
            try{
                if(m.getStock() >= cantitate)
                    m.setStock( m.getStock() - cantitate );
                else{throw stoc_insuficient(m.getStock(), cantitate );}
            }

            catch(int num){
                std::cout<<"Atentie! Cantitatea ceruta este mai mare decat stocul.\n";
                std::cout<<"Stocul curent este: "<<num;
            }

            if(m.getStock() <= 0)
                manualeliceu.erase(remove(manualeliceu.begin(), manualeliceu.end(), man));
            break;
        }
}

ManualLucru Librarie::compara(std::string sub, int cls, int dif, bool rez) //returneaza manualul cel mai ieftin pentru subiectul si clasa selectate
{
    ManualLucru man(cls, sub, -1, 500, dif, rez);
    for(auto &manual : this->manuale)
    {
        if(manual < man && manual.getDificulty()==dif && manual.getRez() == rez) man = manual;
    }
    if(man.getPrice() == 495) //are pretul redus cu 5
        throw produs_inexistent(man);

    return man;
}

ManualLiceu Librarie::compara(std::string sub, int cls, std::string profil) //returneaza manualul cel mai ieftin pentru subiectul si clasa selectate
{
    ManualLiceu man(cls, sub, -1, 500, profil);
    for(auto &manual : this->manualeliceu)
    {
        if(manual < man && manual.getProfil() == profil) man = manual;
    }
    if(man.getPrice() == 510) //manualliceu are +10
        throw produs_inexistent(man);

    return man;
}

Caiet Librarie::compara(std::string tip) //returneaza caietul cel mai ieftin in functie de tip
{
    Caiet cai(160, tip, -1, 500);
    for(auto &caiet : this->caiete)
    {
        if(caiet < cai) cai = caiet;
    }
    if(cai.getPrice() == 500)
        throw produs_inexistent(cai);

    return cai;
}

std::ostream &operator<<( std::ostream &output, const Librarie &lib ) {
    output << "\nName: " << lib.name << "\n";
    for (auto &caiet : lib.caiete)
        output << caiet;
    for (auto &manual : lib.manuale)
        output << manual;
    for (auto &manual : lib.manualeliceu)
        output << manual;
    return output;
}
