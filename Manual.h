#ifndef LIBRARIE_MANUAL_H
#define LIBRARIE_MANUAL_H

#include<iostream>
#include <memory>

class Manual{
private:
    int clasa;
    std::string subject;
    int stock;
    int price;
public:

    Manual(const int &cls, std::string sub, int stoc, int pret);
    virtual std::unique_ptr <Manual> clone() = 0;
    int getClasa();
    virtual int getPrice();
    std::string getSubject();
    int getStock();
    void setStock(int s);
    ~Manual();
    friend std::ostream &operator<<( std::ostream &output, const Manual &m );
    friend bool operator==( const Manual &m1, const Manual &m2);
    friend bool operator<( const Manual &m1, const Manual &m2);
    friend bool operator>( const Manual &m1, const Manual &m2);
    Manual(const Manual &m);
    Manual& operator= (const Manual &m);
};
#endif //LIBRARIE_MANUAL_H
