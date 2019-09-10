#include <iostream>

// Name: David Skrenta

// Write any functions you need here!

int takesIntPtr(int* ptr) {
  return 0; 
}

int takesIntRef(int& ref) {
  return ref;
}

int takesInt(int num) {
  return num;
}

void fillOutputParam(const int& in, int* out) {
  *out = in;
}

int main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.
    
    // 1) Declare an int

    int num = 0;

    // 2) Declare a pointer to that int

    int* numPtr = &num;

    // 3) Increment the int via the pointer

    (*numPtr)++;

    std::cout << num << std::endl;

    // 4) Declare a reference to your int

    int& numRef = num;

    // 5) Increment the int via the reference

    numRef++;

    std::cout << num << std::endl;

    // 6) When you increment the int via the variable declared in #1, from which
    // variables can you see the changes?
    // Answer: You can see the changes from int num as long as you dereference the pointer before incrementing

    // 7) When you increment the int via the pointer declared in #2, from which
    // variables can you see the changes?
    // Answer: You can see the changes from int num after incrementing it's reference

    // 8) When you increment the int via the reference declared in #4, from which
    // variables can you see the changes?
    // Answer: You can see the changes from int num as the reference just points back to that value

    // 9) Write a function that takes an int * parameter. How would you pass the 
    // variable from #1 into this function? (write the function call below)

    takesIntPtr(numPtr);

    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    // Answer: No, types are incompatible

    // takesIntPtr(numRef);

    // 11) Write a function that takes an int & parameter. How would you pass the 
    // variable from #1 into this function? (write the function call below)

    takesIntRef(num);

    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    // Answer: Yes

    takesIntPtr(numPtr);

    // 13) Can you pass your reference from #4 to the function from #11?
    // Answer: Yes

    takesIntRef(numRef);

    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.

    int num1 = 1;
    int num2 = 2;
    int num3 = 3;

    int* outNumPtr;

    fillOutputParam(num1, outNumPtr);
    std::cout << *outNumPtr << std::endl;

    fillOutputParam(num2, outNumPtr);
    std::cout << *outNumPtr << std::endl;

    fillOutputParam(num3, outNumPtr);
    std::cout << *outNumPtr << std::endl;

    // 15) What is/are the difference(s) between output parameters and return values?
    // Answer: Output parameters use references to output values from the function in order to recieve the value. Return values actually return the data from the funciton according to a specific type.

  return 0;
}