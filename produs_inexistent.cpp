#include "produs_inexistent.h"

using namespace std::string_literals;

produs_inexistent::produs_inexistent(Caiet prod) noexcept
        : runtime_error("Produs inexistent: "s +
                        "ati incercat sa gasiti un caiet de tip "s +
                        prod.getType() +
                        " dar acesta nu se afla in stoc.") {}

produs_inexistent::produs_inexistent(ManualLucru prod) noexcept
        : runtime_error("Produs inexistent: "s +
                        "ati incercat sa gasiti un manual de clasa "s +
                        std::to_string(prod.getClasa()) +
                        ", materia "s+
                        prod.getSubject()+
                        ", dificultatea "s+
                        std::to_string(prod.getDificulty())+
                        " dar acesta nu se afla in stoc.") {}

produs_inexistent::produs_inexistent(ManualLiceu prod) noexcept
        : runtime_error("Produs inexistent: "s +
                        "ati incercat sa gasiti un manual de clasa "s +
                        std::to_string(prod.getClasa()) +
                        ", materia "s+
                        prod.getSubject()+
                        " si profilul "s+
                        prod.getProfil()+
                        " dar acesta nu se afla in stoc.") {}
