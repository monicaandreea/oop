#include<vector>
#include "Caiet.h"
#include "Manual.h"
#include "ManualLiceu.h"
#include "ManualLucru.h"

class Librarie{
private:
    std::string name;
    std::vector <Caiet> caiete;
    std::vector < ManualLucru > manuale;
    std::vector < ManualLiceu > manualeliceu;

public:
    Librarie(const std::string &nume);
    virtual ~Librarie();
    void setName(std::string a);
    std::string getName();
    void adauga(Caiet &caiet);  //verifica daca produsul exista deja, iar daca exista ii modifica stocul, daca nu, il adauga la librarie
    void sterge(Caiet &caiet, int cantitate); //verifica daca cantitatea ceruta este mai mare decat stocul, iar daca stocul este 0, sterge produsul
    void adauga(ManualLucru &man);
    void sterge(ManualLucru &man, int cantitate);
    void adauga(ManualLiceu &man);
    void sterge(ManualLiceu &man, int cantitate);
   // std::unique_ptr<Manual> compara(std::string sub, int cls);
    ManualLucru compara(std::string sub, int cls, int dif, bool rez);//returneaza manualul cel mai ieftin pentru subiectul si clasa selectate
    ManualLiceu compara(std::string sub, int cls, std::string profil);
    Caiet compara(std::string tip); //returneaza caietul cel mai ieftin in functie de tip
    friend std::ostream &operator<<( std::ostream &output, const Librarie &lib );
};
