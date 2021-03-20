#include<iostream>
#include "Librarie.h"
#include <utility>

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
            if(c.getStock() >= cantitate)
                c.setStock( c.getStock() - cantitate );
            else std::cout<<"Atentie! Cantitatea ceruta este mai mare decat stocul.("<<c.getStock()<<")\n";

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
            if(m.getStock() >= cantitate)
                m.setStock( m.getStock() - cantitate );
            else std::cout<<"Atentie! Cantitatea ceruta este mai mare decat stocul.("<<m.getStock()<<")\n";

            if(m.getStock() <= 0)
                manuale.erase(remove(manuale.begin(), manuale.end(), man));
            break;
        }
}

Manual Librarie::compara(std::vector<Manual> m, std::string sub, int cls) //returneaza manualul cel mai ieftin pentru subiectul si clasa selectate
{
    Manual man = this->manuale[0];
    for(auto &manual : this->manuale)
    {
        if(manual < man) man = manual;
    }
    return man;
}

Caiet Librarie::compara(std::vector<Caiet> c, std::string tip) //returneaza caietul cel mai ieftin in functie de tip
{
    Caiet cai = this->caiete[0];
    for(auto &caiet : this->caiete)
    {
        if(caiet < cai) cai = caiet;
    }
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
