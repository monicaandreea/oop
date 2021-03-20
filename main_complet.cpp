#include <iostream>
#include <vector>
#include <algorithm>

class Caiet{
private:
    int pages;
    std::string type;
    int stock;
    int price;
public:
    Caiet(const int &pag, std::string tip, int stoc, int pret){
        pages = pag;
        type = tip;
        stock = stoc;
        price = pret;
    }

    int getPages(){
        return pages;
    }

    std::string getType(){
        return type;
    }

    void setStock(int s){
        stock = s;
    }

    int getStock(){
        return stock;
    }

    friend std::ostream &operator<<( std::ostream &output, const Caiet &c ) {
        output<<"\nNumber of pages: "<<c.pages <<"\nType: "<<c.type<<"\nStock: "<<c.stock<<"\nPrice: "<<c.price<<"\n";
        return output;
    }

    friend bool operator==( const Caiet &c1, const Caiet &c2)
    {
        return(c1.price == c2.price && c1.type == c2.type && c1.pages == c2.pages);
    }

    Caiet(const Caiet &c){
        pages = c.pages;
        type = c.type;
        stock = c.stock;
        price = c.price;
    }

    Caiet& operator= (const Caiet &c){
        if( this == &c)
            return *this;
        pages = c.pages;
        type = c.type;
        stock = c.stock;
        price = c.price;

        return *this;
    }

    friend bool operator<( const Caiet &c1, const Caiet &c2)
    {
        return( c1.type == c2.type && ( double(c1.price)/double(c1.pages) < double(c2.price)/double(c2.pages) ));
    }

    friend bool operator>( const Caiet &c1, const Caiet &c2)
    {
        return( c1.type == c2.type && ( double(c1.price)/double(c1.pages) > double(c2.price)/double(c2.pages) ));
    }
};

class Manual{
private:
    int clasa;
    std::string subject;
    int stock;
    int price;
public:

    Manual(const int &cls, std::string sub, int stoc, int pret){
        clasa = cls;
        subject = sub;
        stock = stoc;
        price = pret;
    }

    int getClasa(){
        return clasa;
    }
    std::string getSubject(){
        return subject;
    }

    int getStock(){
        return stock;
    }

    void setStock(int s){
        stock = s;
    }

    ~Manual(){
        //std::cout<<"\ns-a apelat destructorul manual"<<std::endl;
    }

    friend std::ostream &operator<<( std::ostream &output, const Manual &m ) {
        output<<"\nClass: "<<m.clasa <<"\nSubject: "<<m.subject<<"\nStock: "<<m.stock<<"\nPrice: "<<m.price<<"\n";
        return output;
    }

    friend bool operator==( const Manual &m1, const Manual &m2)
    {
        return(m1.price == m2.price && m1.clasa == m2.clasa && m1.subject == m2.subject);
    }

    friend bool operator<( const Manual &m1, const Manual &m2)
    {
       return( m1.clasa == m2.clasa && m1.subject == m2.subject && m1.price<m2.price);
    }

    friend bool operator>( const Manual &m1, const Manual &m2)
    {
        return( m1.clasa == m2.clasa && m1.subject == m2.subject && m1.price>m2.price);
    }

    Manual(const Manual &m){
        clasa = m.clasa;
        subject = m.subject;
        stock = m.stock;
        price = m.price;
    }

    Manual& operator= (const Manual &m){
        if( this == &m)
            return *this;
        clasa = m.clasa;
        subject = m.subject;
        stock = m.stock;
        price = m.price;

        return *this;
    }

};

class Librarie{
private:
    std::string name;
    std::vector <Caiet> caiete;
    std::vector <Manual> manuale;
public:
    Librarie(const std::string &nume): name( nume ){}

    ~Librarie(){
        //std::cout<<"\ns-a apelat destructorul lib"<<std::endl;
    }


    void setName(std::string a){
        name = a;
    }

    std::string getName(){
        return name;
    }

    void adauga(Caiet &caiet){  ///verifica daca produsul exista deja, iar daca exista ii modifica stocul, daca nu, il adauga la librarie
        int ok = 1;
        for(auto &c : this->caiete)
            if( c == caiet)
            {
                c.setStock(c.getStock() + caiet.getStock());
                ok = 0;
                break;
            }
        if(ok == 1) caiete.push_back(caiet);
    }

    void sterge(Caiet &caiet, int cantitate){ ///verifica daca cantitatea ceruta este mai mare decat stocul, iar daca stocul este 0, sterge produsul
        for(auto &c : this->caiete)
            if( c == caiet )
            {
                if(c.getStock() >= cantitate)
                    c.setStock( c.getStock() - cantitate );
                else std::cout<<"Atentie! Cantitatea ceruta este mai mare decat stocul.("<<c.getStock()<<")\n";

                if(c.getStock() <= 0)
                    caiete.erase(remove(caiete.begin(), caiete.end(), caiet));
                break;
            }
    }

    void adauga(Manual &man){
        int ok = 1;
        for(auto &m : this->manuale)
            if( m == man)
            {
                m.setStock(m.getStock() + man.getStock());
                ok = 0;
                break;
            }
        if(ok == 1) manuale.push_back(man);
    }

    void sterge(Manual &man, int cantitate){
        for(auto &m : this->manuale)
            if( m == man )
            {
                if(m.getStock() >= cantitate)
                    m.setStock( m.getStock() - cantitate );
                else std::cout<<"Atentie! Cantitatea ceruta este mai mare decat stocul.("<<m.getStock()<<")\n";

                if(m.getStock() <= 0)
                    manuale.erase(remove(manuale.begin(), manuale.end(), man));
                break;
            }
    }

    Manual compara(std::vector<Manual> m, std::string sub, int cls) //returneaza manualul cel mai ieftin pentru subiectul si clasa selectate
    {
        Manual man = this->manuale[0];
        for(auto &manual : this->manuale)
        {
            if(manual < man) man = manual;
        }
        return man;
    }

    Caiet compara(std::vector<Caiet> c, std::string tip) //returneaza caietul cel mai ieftin in functie de tip
    {
        Caiet cai = this->caiete[0];
        for(auto &caiet : this->caiete)
        {
            if(caiet < cai) cai = caiet;
        }
        return cai;
    }

    friend std::ostream &operator<<( std::ostream &output, const Librarie &lib ) {
        output << "\nName: " << lib.name << "\n";
        for (auto &caiet : lib.caiete)
            output << caiet;
        for (auto &manual : lib.manuale)
            output << manual;
        return output;
    }

};

int main() {
    Librarie lib1("Carturesti");
    Manual man1(7, "mate", 8, 30);
    Manual man2(7, "mate", 3, 20);
    Caiet c1(80, "dictando", 10, 15);
    Caiet c2(160, "dictando", 4, 25);
    Caiet c3(80, "dictando", 5, 15);
    Caiet c4(160, "dictando", 9, 10);
    Caiet c5(160, "velin", 17, 5);
    Manual man3(7, "mate", 10, 20);
    lib1.adauga(man1);
    lib1.adauga(man2);
    lib1.adauga(c1);
    lib1.adauga(c2);
    lib1.adauga(c3);
    lib1.adauga(c4);
    lib1.adauga(c5);
    lib1.adauga(man3);
    lib1.sterge(c3, 7);
    lib1.sterge(c2, 7);
    lib1.sterge(c3, 8);
    lib1.sterge(man1, 8);
    std::cout<<lib1;

    std::cout<<"\nConstructor de copiere:";
    Manual man4 = man3;
    std::cout<<man4;

    if(man2>man1) std::cout<<"este";
    else std::cout<<"nu este";
    if(c2>c3) std::cout<<"este";
    else std::cout<<"nu este";

    std::cout<<lib1.compara({man1, man2}, "mate", 7);
    std::cout<<lib1.compara({c2, c3, c1}, "dictando");
    return 0;
}
