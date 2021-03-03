#include <iostream>
//clasa Librarie si clase prin compunere:
//carti(autor, isbn, nr pag, tip coperta, gen)
//manuale(clasa, materie)
//caiete(tipul, nr pagini)

class Librarie{
private:
    std::string city;
    std::string street;
    int street_num;
    //Carte book;
    //Manual man;
    //Caiet note;
public:
    Librarie(std::string x, std::string y, int z){ //constructor cu parametrii
        city = x;
        street = y;
        street_num = z;
    }
    Librarie(const Librarie& a){ //constructor de copiere

    }
    ~Librarie(){ //deconstructor
        std::cout<<" s-a apelat deconstructorul"<<std::endl;
    }
    //setteri si getteri
    void setCity(std::string a){
        city = a;
    }
    std::string getCity(){
        return city;
    }
    void setStreet(std::string a){
        street = a;
    }
    std::string getStreet(){
        return street;
    }
    void setStreet_num(int a){
        street_num = a;
    }
    int getStreet_num(){
        return street_num;
    }
    friend std::ostream &operator<<(std::ostream &afis, const Librarie &lib){
        afis<<lib.city<<" "<<lib.street<<" "<<lib.street_num<<std::endl;
        return afis;
    }
};



int main() {
    Librarie lib("Bucuresti", "Emil Racovita", 2);
    //lib.setCity("Bucuresti")
    std::cout<< lib.getCity();
    afis<<lib;
    return 0;
}
