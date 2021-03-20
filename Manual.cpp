#include "Manual.h"
#include <utility>
Manual::Manual(const int &cls, std::string sub, int stoc, int pret){
    clasa = cls;
    subject = sub;
    stock = stoc;
    price = pret;
}

int Manual::getClasa(){
    return clasa;
}
std::string Manual::getSubject(){
    return subject;
}

int Manual::getStock(){
    return stock;
}

void Manual::setStock(int s){
    stock = s;
}

Manual::~Manual(){
    //std::cout<<"\ns-a apelat destructorul manual"<<std::endl;
}

std::ostream &operator<<( std::ostream &output, const Manual &m ) {
    output<<"\nClass: "<<m.clasa <<"\nSubject: "<<m.subject<<"\nStock: "<<m.stock<<"\nPrice: "<<m.price<<"\n";
    return output;
}

bool operator==( const Manual &m1, const Manual &m2)
{
    return(m1.price == m2.price && m1.clasa == m2.clasa && m1.subject == m2.subject);
}

bool operator<( const Manual &m1, const Manual &m2)
{
    return( m1.clasa == m2.clasa && m1.subject == m2.subject && m1.price<m2.price);
}

bool operator>( const Manual &m1, const Manual &m2)
{
    return( m1.clasa == m2.clasa && m1.subject == m2.subject && m1.price>m2.price);
}

Manual::Manual(const Manual &m){
    clasa = m.clasa;
    subject = m.subject;
    stock = m.stock;
    price = m.price;
}

Manual& Manual::operator= (const Manual &m){
    if( this == &m)
        return *this;
    clasa = m.clasa;
    subject = m.subject;
    stock = m.stock;
    price = m.price;

    return *this;
}
