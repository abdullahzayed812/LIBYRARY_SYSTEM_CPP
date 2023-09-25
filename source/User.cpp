#include "../headers/User.h"

#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

User::User() {
  this->id = -1;
  this->name = "";
  this->len = 0;
}

void User::read() {
  cout << "Enter user name: ";
  cin >> this->name;
  cout << "Enter user id: ";
  cin >> this->id;
}

void User::borrow(const int& bookId) { this->userBooksIds[this->len++] = bookId; }

void User::returnCopy(const int& bookId) {
  bool removed = false;
  for (int i = 0; i < this->len; i++) {
    if (this->userBooksIds[i] == bookId) {
      for (int j = i + 1; j < this->len; j++) {
        // Shift array left to remove this book that has bookId.
        this->userBooksIds[j - 1] = this->userBooksIds[j];
      }
      removed = true;
      this->len--;
      break;
    }
  }

  if (!removed) {
    cout << "\n";
    cout << "User " << this->name << " never borrowed book id " << bookId;
    cout << "\n";
  }
}

bool User::isBorrowed(const int& bookId) {
  for (int i = 0; i < this->len; i++) {
    if (this->userBooksIds[i] == bookId) {
      return true;
    }
  }
  return false;
}

void User::print() {
  if (this->len > 0) {
    sort(this->userBooksIds, this->userBooksIds + len);

    cout << "User " << this->name << " is borrowed books ids ";

    for (int i = 0; i < this->len; i++) {
      cout << this->userBooksIds[i] << ", ";
    }
  } else {
    cout << "User " << this->name << " never borrow books.";
  }
  cout << "\n";
}