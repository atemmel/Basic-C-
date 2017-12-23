#ifndef FILTERED_INPUT_H
#define FILTERED_INPUT_H

#include <iostream>
#include <string>

/*
 *	Kontrollerar huruvida en sträng kan anses vara en 
 *	godtycklig epostadress, tex:
 *	abc@example.com
 *
 *	@param emailStr Strängen att undersöka
 *	@return True om strängen kan vara en epostadress
 */
bool isValidEmail(const std::string & emailStr);

/*
 *	Parametrar till filteredInput:
 *	ALPHA: Alfabetiska tecken, godkända namn
 *	NUMERIC: Siffror, godkända telefonnummer
 *	ALPHANUMERIC: Alphanumeriska tecken, Godkända meningar
 *	MAIL: Godkända epostadresser
 *	DATE: Godkända datum (YYYYMMDD)
 *	BOOLEAN: y eller n (Ja eller nej))
 */
enum Filter {ALPHA, NUMERIC, ALPHANUMERIC, MAIL, DATE, BOOLEAN};

/*
 *	Tar användarinmatningar tills en sträng anses
 *	tillfredsställande enligt ett filter
 *
 * 	@param input Den sträng som resultatet skall landa i
 *	@param filter Vilket filter metoden skall arbeta efter
 *	@param ignore De tecken metoden skall filtrera
 */
void filteredInput(std::string & input, const Filter & filter);
void filteredInput(std::string & input, const std::string & ignore);

#endif
