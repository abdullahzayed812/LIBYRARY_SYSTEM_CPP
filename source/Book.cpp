#include "../headers/Book.h"

#include <assert.h>

#include <iostream>

using std::cin;
using std::cout;

Book::Book() {
  this->id = -1;
  this->name = "";
  this->totalQuantity = this->totalBorrowed = 0;
}

void Book::read() {
  cout << "Enter book name: ";
  cin >> this->name;
  cout << "Enter book id: ";
  cin >> this->id;
  cout << "Enter book quantity: ";
  cin >> this->totalQuantity;
}

bool Book::borrow() {
  if (this->totalQuantity - this->totalBorrowed == 0) {
    return false;
  }
  this->totalBorrowed++;
  return true;
}

bool Book::hasPrefix(const string& prefix) {
  if (this->name < prefix) {
    return false;
  }
  for (int i = 0; i < prefix.size(); i++) {
    if (this->name[i] != prefix[i]) {
      return false;
    }
  }
  return true;
}

void Book::returnCopy() {
  assert(this->totalBorrowed > 0);
  this->totalBorrowed--;
}

void Book::print() {
  cout << "\n";
  cout << "id = " << this->id << ", name = " << this->name << ", total quantity = " << this->totalQuantity
       << ", total borrowed = " << this->totalBorrowed;
  cout << "\n";
}
