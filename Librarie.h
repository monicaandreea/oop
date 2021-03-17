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
    Librarie(const Librarie& lib);
    virtual ~Librarie();
    void setName(std::string a);
    std::string getName();
    friend std::ostream &operator<<( std::ostream &output, const Librarie &lib );
};