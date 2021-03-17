#include<iostream>

class Caiet{
private:
    int pages;
    std::string type;
    int stock;
    int price;
public:
    Caiet(const int &pag, std::string tip, int stoc, int price);
    int getPages();
    std::string getType();
    int getStock();
    Caiet &operator=(const Caiet &c);
    friend std::ostream &operator<<( std::ostream &output, const Caiet &c );

};