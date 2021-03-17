#include<iostream>
#include "Caiet.h"

Caiet::Caiet(const int &pag, std::string tip, int stoc, int pret){
    pages = pag;
    type = tip;
    stock = stoc;
    price = pret;
}

int Caiet::getPages(){
    return pages;
}

std::string getType(){
    return type;
}

std::string getStock(){
    return stock;
}

std::ostream &operator<<( std::ostream &output, const Caiet &c ) {
    output<<"\nNumber of pages: "<<c.pages <<"\nType: "<<c.type<<"\nStock: "<<c.stock<<"\n";
    return output;
}