#include "Manual.h"

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

Manual::~Manual(){
    std::cout<<"\ns-a apelat destructorul"<<std::endl;
}

std::ostream &operator<<( std::ostream &output, const Manual &m ) {
    output<<"\nClass: "<<m.clasa <<"\nSubject: "<<m.subject<<"\nStock: "<<m.stock<<"\n";
    return output;
}
