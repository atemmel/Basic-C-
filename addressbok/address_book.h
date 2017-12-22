#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include "contact.h"
#include "filtered_input.h"
#include <fstream>
#include <vector>

void addContact(const char * fileName);
void searchContact(const char * fileName);
void removeContact(const char * fileName);

#endif
