#include <iostream>
#include <string>
#include <vector>

// Names: David Skrenta
//
//

// 6) implement a templated version of AddToValues, "AddToValues2".
template <typename T>
void AddToValues2(std::vector<T> v1, T v2) {
  for (int i = 0; i < v1.size(); i++) {
    v1[i] += v2;
  }
}

struct StructWithInt {
  int num;

  StructWithInt* operator+=(const StructWithInt struct_int) {
    this->num += struct_int.num;
    return this;
  }
};

int main() {
    // 7) call AddToValues2, passing in an int vector and another int.

    std::vector<int> intVector;
    AddToValues2(intVector, 1);

    // 8) compile this file to object code (g++ -std=c++11 -Wall exercises2.cpp -o exercises2.o),
    // then run `nm -C exercises2.o`. How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //

    // There should be one int version now

    // 9) call AddToValues2, passing in a vector of a non-int type and a value that you can add
    // successfully to the elements

    std::vector<double> doubleVector;
    AddToValues2(doubleVector, 1.2);

    // 10) compile this file to object code (g++ -std=c++11 -Wall exercises2.cpp -o exercises2.o),
    // then run `nm -C exercises2.o`. How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //
    // There should be an int version and a double version

    // 11) Experiment to find calls to this function that you would like to work but that do
    // not yet work. for each function call that doesn't work, comment about what type of
    // error is produced.

    // std::vector<std::string> stringVector;
    // AddToValues2(stringVector, "Stuff...");
    // no instance of function template "AddToValues2" matches the argument list -- argument types are: (std::__1::vector<std::__1::string, std::__1::allocator<std::__1::string>>, const char [9])

    // 12) Create a struct that has an int field. Instantiate a vector of these structs.
    // Instantiate another instance of this struct.
    StructWithInt struct_int{ 1 };

    // 13) Call AddToValues2 w/ the vector of structs and single struct from #12
    // Is there an error? If yes, what is it?
    //
    // Answer:
    std::vector<StructWithInt> struct_int_vector{struct_int};
    AddToValues2(struct_int_vector, struct_int);

    for (int i = 0; i < struct_int_vector.size(); i++) {
      std::cout << struct_int_vector[i].num << std::endl;
    }

    // 14) If there was an error, attempt to fix it.
}
