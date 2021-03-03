#include <iostream>
//#include <fstream>
//clasa Student si clase prin compunere:
//carti(nume, autor,  nr pag)
//manuale(clasa, materie)
//caiete(tipul, nr pagini)

/*
class Carte{
private:
    std::string name;
    std::string author;
    int num_pag;
public:

};

class Manual{
private:
    int clasa;
    std::string subject;
public:

};
*/
class Caiet{
private:
    int pages;
    std::string type;
public:
    Caiet(){
        pages = 0;
        type = "";
    }
    Caiet(int a, std::string b){
        pages = a;
        type = b;
    }
    void setPages(int a){
        pages = a;
    }
    int getPages(){
        return pages;
    }
    void setType(std::string a){
        type = a;
    }
    std::string getType(){
        return type;
    }

    friend std::ostream &operator<<( std::ostream &output, const Caiet &c ) {
        output<<"\nNumber of pages: "<<c.pages <<"\nType: "<<c.type;
        return output;
    }

};

class Student{
private:
    std::string name;
    int age;
    Caiet notebook;

public:
    Student(std::string a, int b, Caiet c)://constructor cu parametrii
        name{ a }, age{ b }, notebook{ c }
    {
    }

    Student(const Student& a){ //constructor de copiere

    }
    ~Student(){ //destructor
        std::cout<<"\ns-a apelat destructorul"<<std::endl;
    }
    //setteri si getteri
    void setName(std::string a){
        name = a;
    }
    std::string getName(){
        return name;
    }
    void setAge(int a){
        age = a;
    }
    int getAge(){
        return age;
    }

    friend std::ostream &operator<<( std::ostream &output, const Student &lib ) {
        output<<"Name: "<< lib.name <<"\nAge: " << lib.age<<"\nCaiet: "<<lib.notebook;
        return output;
    }

};



int main() {
    Student lib("Monica", 19, {70, "dictando"});
    //lib.setName("Bucuresti")
    //std::cout<< lib.getName();
    std::cout<<lib;
    return 0;
}
