#include<iostream>

class Manual{
private:
    int clasa;
    std::string subject;
    int stock;
    int price;
public:

    Manual(const int &cls, std::string sub, int stoc, int pret);
    int getClasa();
    std::string getSubject();
    int getStock();
    virtual ~Manual();
    friend std::ostream &operator<<( std::ostream &output, const Manual &m );
};