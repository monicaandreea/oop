#include "stoc_insuficient.h"

using namespace std::string_literals;

stoc_insuficient::stoc_insuficient(int actual, int necesar) noexcept
        : runtime_error("Stoc insuficient: "s +
                        "ati incercat sa stergeti "s +
                        std::to_string(necesar)
                        + ", dar aveti doar "s +
                        std::to_string(actual)) {}