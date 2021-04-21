#ifndef LIBRARIE_PRODUS_INEXISTENT_H
#define LIBRARIE_PRODUS_INEXISTENT_H

#include <stdexcept>
#include "Caiet.h"
#include "Manual.h"

class produs_inexistent : public std::runtime_error {
public:
    produs_inexistent(Caiet prod) noexcept;
    produs_inexistent(Manual prod) noexcept;
};

#endif //LIBRARIE_PRODUS_INEXISTENT_H