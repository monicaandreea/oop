#ifndef LIBRARIE_CAIET_H
#define LIBRARIE_CAIET_H

#include<iostream>

class Caiet{
private:
    int pages;
    std::string type;
    int stock;
    int price;
public:
    Caiet(const int &pag, std::string tip, int stoc, int pret);
    int getPages();
    std::string getType();
    void setStock(int s);
    int getStock();
    friend std::ostream &operator<<( std::ostream &output, const Caiet &c );
    friend bool operator==( const Caiet &c1, const Caiet &c2);
    Caiet(const Caiet &c);
    Caiet& operator= (const Caiet &c);
    friend bool operator<( const Caiet &c1, const Caiet &c2);
    friend bool operator>( const Caiet &c1, const Caiet &c2);
};
#endif //LIBRARIE_CAIET_H
