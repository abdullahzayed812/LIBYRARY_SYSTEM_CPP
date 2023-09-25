#include "../headers/Global.h"

bool compareByName(const Book& a, const Book& b) { return a.name > b.name; }

bool compareById(const Book& a, const Book& b) { return a.id > b.id; }
