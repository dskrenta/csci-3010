#include <iostream>
#include <string>

#include "Disease.h"

// initialize our static counter
int Disease::counter_ = 0;

std::ostream& operator<<(std::ostream &os, const Disease &d) {
    os << d.get_name();
    // TODO: print out more information if you want to
    return os;
}

