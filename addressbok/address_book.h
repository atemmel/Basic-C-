#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include "contact.h"
#include "filtered_input.h"
#include <fstream>
#include <vector>

/**
 *	För en användardialog och lägger därefter till en
 *	kontakt till en fil.
 *
 * 	@param fileName Namnet på den fil kontakten skall läggas till i
 */
void addContact(const char * fileName);

/**
 *	För en användardialog och söker därefter efter
 *	en kontakt i en fil.
 *
 *	@param fileName Namnet på den fil som skall sökas ur
 */
void searchContact(const char * fileName);

/**
 *	För en användardialog medans användaren får gå
 *	igenom en fil men kontakter och välja vilka som
 *	skall tas bort
 *
 *	@param fileName Namnet på den fil som kontakter skall tas bort ifrån
 */
void removeContact(const char * fileName);

#endif
