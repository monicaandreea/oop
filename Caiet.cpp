#include<iostream>
#include "Caiet.h"
#include <utility>

Caiet::Caiet(const int &pag, std::string tip, int stoc, int pret){
    pages = pag;
    type = tip;
    stock = stoc;
    price = pret;
}

int Caiet::getPages(){
    return pages;
}

int Caiet::getPrice(){
    return price;
}

std::string Caiet::getType(){
    return type;
}

void Caiet::setStock(int s){
    stock = s;
}

int Caiet::getStock(){
    return stock;
}

std::ostream &operator<<( std::ostream &output, const Caiet &c ) {
    output<<"\nNumber of pages: "<<c.pages <<"\nType: "<<c.type<<"\nStock: "<<c.stock<<"\nPrice: "<<c.price<<"\n";
    return output;
}

bool operator==( const Caiet &c1, const Caiet &c2)
{
    return(c1.price == c2.price && c1.type == c2.type && c1.pages == c2.pages);
}

Caiet::Caiet(const Caiet &c){
    pages = c.pages;
    type = c.type;
    stock = c.stock;
    price = c.price;
}

Caiet& Caiet::operator= (const Caiet &c){
    if( this == &c)
        return *this;
    pages = c.pages;
    type = c.type;
    stock = c.stock;
    price = c.price;

    return *this;
}

bool operator<( const Caiet &c1, const Caiet &c2)
{
    return( c1.type == c2.type && ( double(c1.price)/double(c1.pages) < double(c2.price)/double(c2.pages) ));
}

bool operator>( const Caiet &c1, const Caiet &c2)
{
    return( c1.type == c2.type && ( double(c1.price)/double(c1.pages) > double(c2.price)/double(c2.pages) ));
}
