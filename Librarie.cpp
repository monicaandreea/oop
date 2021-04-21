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

void Librarie::adauga(Manual &man){
    int ok = 1;
    for(auto &m : this->manuale)
        if( m == man)
        {
            m.setStock(m.getStock() + man.getStock());
            ok = 0;
            break;
        }
    if(ok == 1) manuale.push_back(man);
}

void Librarie::sterge(Manual &man, int cantitate){
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

Manual Librarie::compara(std::string sub, int cls) //returneaza manualul cel mai ieftin pentru subiectul si clasa selectate
{
    Manual man(cls, sub, -1, 500);
    for(auto &manual : this->manuale)
    {
        if(manual < man) man = manual;
    }
    if(man.getPrice() == 500)
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
    return output;
}
