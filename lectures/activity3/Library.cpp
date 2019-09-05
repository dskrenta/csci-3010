#include <iostream>
#include <string>
#include <vector>

#include "Library.h"

// Implement bool Book::operator==(const Book& b)
bool Book::operator==(const Book& b) {
  return title == b.title && author == b.author;
}

std::ostream & operator<<(std::ostream & os, const Book & b) {
  os << b.title << "by " << b.author << std::endl;
  return os;
}

/**
  Zero argument constructor initializes a library with a shelf but no books.
*/
Library::Library() {
  std::vector<Book> tmp;
  shelf_ = tmp;  // initialize my shelf
}

/**
  Prints out each book in the library, one per line to cout
*/
void Library::PrintBooks() {
  for (Book b : shelf_) {
    std::cout << b.title << " by " << b.author << std::endl;
  }
}

/*
std::ostream & operator<<(std::ostream & os, const Library & l) {
  for (Book b: l.shelf_) {
    os << b;
  }
}
*/

/**
  Adds a passsed book in the last position of the library shelf
*/
void Library::Donate(Book b) {
  shelf_.push_back(b);
}
