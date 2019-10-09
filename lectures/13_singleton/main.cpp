#include <iostream>
#include "Earth.h"

// Names:
//

int main(int argc, char **argv){
    // 0) Implement your Earth's constructor in Earth.cpp

    // Done

    // 1) Get an instance of your earth object

    Earth& earth = Earth::GetInstance();

    // 2) Get another instance of your earth object

    Earth& earth1 = Earth::GetInstance();

    // 3) Test to see if the two Earth instances from #1 and #2 are stored at the same
    // location in memory.

    // #1 and #2 are stored in the same memory location
    if (&earth == &earth1) {
      std::cout << "Same memory location" << std::endl;
    }
    else {
      std::cout << "Different memory location" << std::endl;
    }

    // 3) Call IncreasePopulation from one of your Earth instances. Can you see this change
    // from your other Earth instance?

    earth.IncreasePopulation();
    std::cout << earth.get_population() << std::endl;
    std::cout << earth1.get_population() << std::endl;
    // yes

    // 4) Create a public field in your Earth object. Do you need an instance of an Earth object
    // to access this field?

    // Yes, you'll need an instance to access an instance variable
    std::cout << earth.new_field_ << std::endl;

	return 0;
}
