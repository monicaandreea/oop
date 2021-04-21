#include "produs_inexistent.h"
#include "Caiet.h"

using namespace std::string_literals;

produs_inexistent::produs_inexistent(Caiet prod) noexcept
        : runtime_error("Produs inexistent: "s +
                        "ati incercat sa gasiti un caiet de tip "s +
                        prod.getType() +
                        " dar acesta nu se afla in stoc.") {}

produs_inexistent::produs_inexistent(Manual prod) noexcept
        : runtime_error("Produs inexistent: "s +
                        "ati incercat sa gasiti un manual de clasa "s +
                        std::to_string(prod.getClasa()) +
                        " si materia "s+
                        prod.getSubject()+
                        " dar acesta nu se afla in stoc.") {}
