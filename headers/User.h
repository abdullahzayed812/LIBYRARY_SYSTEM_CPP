#ifndef USER_H
#define USER_H

#include <string>

#include "../headers/Book.h"

using namespace std;

// const int MAX_BOOKS = 10;

struct User {
  int id;
  string name;
  int len;
  int userBooksIds[10];

  User();
  void read();
  void borrow(const int& bookId);
  void returnCopy(const int& bookId);
  bool isBorrowed(const int& bookId);
  void print();
};

#endif