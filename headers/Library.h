#ifndef LIBRARY_H
#define LIBRARY_H

#include "../headers/Book.h"
#include "../headers/User.h"

const int MAX_BOOKS = 10;
const int MAX_USERS = 10;

struct Library {
  int totalBooks;
  int totalUsers;
  Book books[10];
  User users[10];

  Library();
  void run();
  int menu();
  void addBook();
  void searchBooksByPrefix();
  int findBookIndexByName(const string& bookName);
  int findUserIndexByName(const string& username);
  void printWhoBorrowedBookByName();
  void printLibraryById();
  void printLibraryByName();
  void addUser();
  bool readUsernameAndBookName(int& userIndex, int& bookIndex, int trials);
  void userBorrowBook();
  void userReturnBook();
  void printUsers();
};

#endif