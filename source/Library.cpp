#include "../headers/Library.h"

#include <algorithm>
#include <iostream>

#include "../headers/Global.h"

using std::cin;
using std::cout;
using std::string;

Library::Library() { this->totalBooks = this->totalUsers = 0; }

void Library::run() {
  while (true) {
    int choice = this->menu();

    if (choice == 1) {
      this->addBook();
    } else if (choice == 2) {
      this->searchBooksByPrefix();
    } else if (choice == 3) {
      this->printWhoBorrowedBookByName();
    } else if (choice == 4) {
      this->printLibraryById();
    } else if (choice == 5) {
      this->printLibraryByName();
    } else if (choice == 6) {
      this->addUser();
    } else if (choice == 7) {
      this->userBorrowBook();
    } else if (choice == 8) {
      this->userReturnBook();
    } else if (choice == 9) {
      this->printUsers();
    } else {
      break;
    }
  }
}

int Library::menu() {
  int choice = -1;
  while (choice == -1) {
    cout << "\nLibrary Menu\n";
    cout << "1) Add book.\n";
    cout << "2) Search books by prefix.\n";
    cout << "3) Print who borrowed books by name.\n";
    cout << "4) Print library by id.\n";
    cout << "5) Print library by name.\n";
    cout << "6) Add user.\n";
    cout << "7) User borrow book.\n";
    cout << "8) User return book.\n";
    cout << "9) Print users.\n";
    cout << "10) Exit.\n";

    cout << "Enter your menu choice [1 - 10]: ";
    cin >> choice;

    if (cin.fail()) {
      cin.clear();
      cin.ignore();
      choice = -1;
    }

    if (!(choice >= 1 && choice <= 10)) {
      cout << "Invalid choice. Try again.\n";
      choice = -1;
    }
  }
  return choice;
}

void Library::addBook() { this->books[this->totalBooks++].read(); }

void Library::searchBooksByPrefix() {
  cout << "Enter book name prefix: ";
  string prefix;
  cin >> prefix;

  int count = 0;
  for (int i = 0; i < this->totalBooks; i++) {
    if (this->books[i].hasPrefix(prefix)) {
      cout << books[i].name << "\n";
      count++;
    }
  }

  if (!count) {
    cout << "No books with such prefix.\n";
  }
}

int Library::findBookIndexByName(const string& bookName) {
  for (int i = 0; i < this->totalBooks; i++) {
    if (this->books[i].name == bookName) {
      return i;
    }
  }
  return -1;
}

int Library::findUserIndexByName(const string& username) {
  for (int i = 0; i < this->totalUsers; i++) {
    if (this->users[i].name == username) {
      return i;
    }
  }
  return -1;
}

void Library::printWhoBorrowedBookByName() {
  cout << "Enter book name: ";
  string bookName;
  cin >> bookName;

  int bookIndex = this->findBookIndexByName(bookName);

  if (bookIndex == -1) {
    cout << "Invalid book name.\n";
    return;
  }

  if (this->books[bookIndex].totalBorrowed == 0) {
    cout << "No borrowed for this book.\n";
    return;
  }

  int bookId = this->books[bookIndex].id;

  for (int i = 0; i < this->totalUsers; i++) {
    if (this->users[i].isBorrowed(bookId)) {
      cout << users[i].name << "\n";
    }
  }
}

void Library::printLibraryById() {
  sort(this->books, this->books + this->totalBooks, compareById);

  cout << "\n";
  for (int i = 0; i < this->totalBooks; i++) {
    this->books[i].print();
  }
}

void Library::printLibraryByName() {
  sort(this->books, this->books + this->totalBooks, compareByName);

  cout << "\n";
  for (int i = 0; i < this->totalBooks; i++) {
    this->books[i].print();
  }
}

void Library::addUser() { this->users[this->totalUsers++].read(); }

bool Library::readUsernameAndBookName(int& userIndex, int& bookIndex, int trial = 3) {
  string username, bookName;

  while (trial--) {
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter book name: ";
    cin >> bookName;

    userIndex = findUserIndexByName(username);
    if (userIndex == -1) {
      cout << "Invalid username. Try agin\n";
      continue;
    }

    bookIndex = findBookIndexByName(bookName);
    if (bookIndex == -1) {
      cout << "Invalid book name. Try agin\n";
      continue;
    }

    return true;
  }
  cout << "You did several trials. Try later\n";
  return false;
}

void Library::userBorrowBook() {
  int userIndex, bookIndex;

  if (!this->readUsernameAndBookName(userIndex, bookIndex)) {
    return;
  }

  int userId = this->users[userIndex].id;
  int bookId = this->books[bookId].id;

  if (!this->books[bookIndex].borrow()) {
    cout << "No more copies available right now.\n";
  } else {
    this->users[userIndex].borrow(bookId);
  }
}

void Library::userReturnBook() {
  int userIndex, bookIndex;

  if (!this->readUsernameAndBookName(userIndex, bookIndex)) {
    return;
  }

  int bookId = this->books[bookIndex].id;
  this->books[bookIndex].returnCopy();
  this->users[userIndex].returnCopy(bookId);
}

void Library::printUsers() {
  cout << "\n";
  for (int i = 0; i < this->totalUsers; i++) {
    users[i].print();
  }
}