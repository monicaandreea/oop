#include<vector>
#include "Caiet.h"
#include "Manual.h"


class Librarie{
private:
    std::string name;
    std::vector <Caiet> caiete;
    std::vector <Manual> manuale;
public:
    Librarie(const std::string &nume);
    virtual ~Librarie();
    void setName(std::string a);
    std::string getName();
    void adauga(Caiet &caiet);  //verifica daca produsul exista deja, iar daca exista ii modifica stocul, daca nu, il adauga la librarie
    void sterge(Caiet &caiet, int cantitate); //verifica daca cantitatea ceruta este mai mare decat stocul, iar daca stocul este 0, sterge produsul
    void adauga(Manual &man);
    void sterge(Manual &man, int cantitate);
    Manual compara(std::vector<Manual> m, std::string sub, int cls); //returneaza manualul cel mai ieftin pentru subiectul si clasa selectate
    Caiet compara(std::vector<Caiet> c, std::string tip); //returneaza caietul cel mai ieftin in functie de tip
    friend std::ostream &operator<<( std::ostream &output, const Librarie &lib );

};
