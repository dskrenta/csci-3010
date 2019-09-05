#include <iostream>
#include <vector>
#include "Library.h"

// Name(s): David Skrenta
//
// Complete numbered coding tasks.
// Answer the questions with "Answer: " in the comments in the comments.
// Turn in run_library.cpp on Canvas before the end of class. (only this file!)

int main() {
  // 1) Instantiate a couple Books. Set their fields equal to some values.
  // Print out the values of the books' fields.

  Book book1;
  book1.title = "Wizardly things";
  book1.author = "Meenan Keenan";

  Book book2;
  book2.title = "Nice book title";
  book2.author = "Miroh";

  std::cout << book1.title << " by " << book1.author << std::endl;
  std::cout << book2.title << " by " << book2.author << std::endl;

  // 2) Instantiate a Library.

  Library lib;

  // 3) Add a void Donate(Book b) method to your Library class.
  // Your Library should store the new book at the end of its shelf.

  // Done

  // 4) Donate one of the Books that you instantiated to your Library.

  lib.Donate(book1);

  // 5) Print out the books in the Library (use the given PrintBooks method)

  lib.PrintBooks();

  // 6) Change the title and/or author of the book that you donated to
  // something different.
  // Print out the new book information, then print out the books in your
  // Library. Did changing the Book information change it in your Library?
  //
  // Answer (and your hypothesis for why/why not): This operation did not change the Book information in the
  // Library because the struct value was appended to the vector inside which was passed by value.

  book1.title = "Something else";
  book1.author = "Someone else";
  std::cout << book1.title << " by " << book1.author << std::endl;
  lib.PrintBooks();

  // 7) Create two Books that are separate structs (not pointers or references)
  // but that have the same information.
  // use the == operator to test if they are equal. What happens?
  // if it succeeds, are these equal?
  //
  // Answer: Structs cannot be compared with == as there is no default behavior defined, the values within the structs are equal.

  Book book3;
  book3.title = "Cool title";
  book3.author = "Cool author";

  Book book4;
  book4.title = "Cool title";
  book4.author = "Cool author";

  // 8) Create two Book references to your Books from # 7.
  // use the == operator to test if they are equal. What happens?
  // if it succeeds, are these equal?
  //
  // Answer: Does not succeed, these values are not equal since both structs have a different memory address.

  Book& book3Ref = book3;
  Book& book4Ref = book4;

  if (book3Ref == book4Ref) {
    std::cout << true << std::endl;
  }

  // 9) Create two Book pointers to your Books from # 7.
  // use the == operator to test if they are equal. What happens?
  // if it succeeds, are these equal?
  //
  // Answer: Does not succeed, these values are not equal since the memory addresses for book3 and book4 are different

  Book* book3Pointer = &book3;
  Book* book4Pointer = &book4;

  if (book3Pointer == book4Pointer) {
    std::cout << true << std::endl;
  }

  // 10) (Given in lecture)

  // overloading: multipe methods or functions with the same name
  //  void Dontate(Book b, int copies)

  // overriding: when a function signature is the same as the base lass or an abstract function
  // bool Point::operator==(const Point &first, const Point &other) {
  //   return first.x_ == other.x_ && first.y_ == other.y_;
  // }
}
