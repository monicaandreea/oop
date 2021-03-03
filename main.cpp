#include <iostream>
//#include <fstream>
//clasa Student si clase prin compunere:
//carti(nume, autor,  nr pag)
//manuale(clasa, materie)
//caiete(tipul, nr pagini)


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
    Manual(){
        clasa = 0;
        subject = "";
    }
    Manual(int a, std::string b){
        clasa = a;
        subject = b;
    }
    void setClasa(int a){
        clasa = a;
    }
    int getClasa(){
        return clasa;
    }
    void setSubject(std::string a){
        subject = a;
    }
    std::string getSubject(){
        return subject;
    }

    friend std::ostream &operator<<( std::ostream &output, const Manual &m ) {
        output<<"\nClass: "<<m.clasa <<"\nSubject: "<<m.subject;
        return output;
    }
};

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
    Manual man;
public:
    Student(std::string a, int b, Caiet c, Manual m)://constructor cu parametrii
        name{ a }, age{ b }, notebook{ c }, man{ m }
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
        output<<"Name: "<< lib.name <<"\nAge: " << lib.age<<"\nCaiet: "<<lib.notebook <<"\nManual: "<<lib.man;
        return output;
    }

};



int main() {
    Student lib("A", 15, {70, "dictando"}, {9, "romana"});
    std::cout<<lib;
    return 0;
}
