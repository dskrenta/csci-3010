#include <iostream>
#include <string>
#include <vector>

// Names: David Skrenta
//
//


// 1) implement two functions, AddToValues(std::vector<int> v1, int v2)
// and AddToValues(std::vector<double> v1, double v2)

void AddToValues(std::vector<int> v1, int v2) {
  for (int i = 0; i < v1.size(); i++) {
    v1[i] += v2;
  }
}

void AddToValues(std::vector<double> v1, double v2) {
  for (int i = 0; i < v1.size(); i++) {
    v1[i] += v2;
  }
}

// 2) Do your AddToValues functions have return values? why/ why not?
// Answer: Does not have return values because we are just modifying the passed vector


int main() {
    // 3) Instantiate an int vector
    std::vector<int> intVector;

    // 4) call AddToValues, passing in your int vector and another int.
    AddToValues(intVector, 1);

    // 5) compile this file to object code (g++ -std=c++11 -Wall exercises.cpp -o exercises.o),
    // then run `nm -C exercises.o`. How many versions of the AddToValues function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //
    // To making searching through the output easier, you can pipe the output of nm to grep
    // `nm -C exercises.o | grep "TextToFindHere"`
    //
    // If the -C flag isn't working, you can omit it and still complete the exercise--this flag
    // makes the output easier to read but isn't strictly necessary

    // There should be two compiled versions of AddToValues, one with a vector of ints and int as params, and one with a vector of doubles and a double
}
