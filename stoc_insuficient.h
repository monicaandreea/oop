#ifndef LIBRARIE_STOC_INSUFICIENT_H
#define LIBRARIE_STOC_INSUFICIENT_H

#include <stdexcept>

class stoc_insuficient : public std::runtime_error {
public:
    stoc_insuficient(int actual, int necesar) noexcept;
};

#endif //LIBRARIE_STOC_INSUFICIENT_H