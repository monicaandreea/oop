#include<iostream>
#include "Librarie.h"
#include <utility>

Librarie::Librarie(const std::string &nume): name( nume ){}

Librarie &Librarie::operator=(const Librarie& lib){
    if(this != &lib){
        name = lib.name;
    }
    std::cout << "lib = librarie " << name <<"\n";
    return *this;
}

Librarie::~Librarie(){
    std::cout<<"\ns-a apelat destructorul"<<std::endl;
}

void Librarie::setName(std::string a){
    name = a;
}

std::string Librarie::getName(){
    return name;
}

std::ostream &operator<<( std::ostream &output, const Librarie &lib ) {
    output<<"Name: "<< lib.name <<"\n";
    return output;
}

void Librarie::manuale( const Manual &manual){

}

void Librarie::caiete( const Caiet &caiet){

}
