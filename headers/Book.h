#ifndef BOOK_H
#define BOOK_H

#include <string>

using std::string;

struct Book {
  int id;
  string name;
  int totalQuantity;
  int totalBorrowed;

  Book();
  void read();
  bool borrow();
  bool hasPrefix(const string& prefix);
  void returnCopy();
  void print();
};

#endif