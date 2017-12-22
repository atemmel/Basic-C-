#ifndef FILTERED_INPUT_H
#define FILTERED_INPUT_H

#include <iostream>
#include <string>

enum Filter {ALPHA, NUMERIC, ALPHANUMERIC, MAIL, DATE, BOOLEAN};

void filteredInput(std::string & input, const Filter & filter);
void filteredInput(std::string & input, const std::string & ignore);

#endif
