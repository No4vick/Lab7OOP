#include <iostream>
#include "error_custom.h"

const char* Errors::getError() {
	return error;
}

IllegalInputType::IllegalInputType(const char* err) {
	if (!error)
		delete[] error;
	error = new char[strlen(err) + 1];
	strcpy_s((char*)error, strlen(err) + 1, err);
}

IllegalInputType::IllegalInputType() {
}

IncorrectDateFormat::IncorrectDateFormat(const char* err) {
	if (!error)
		delete[] error;
	error = new char[strlen(err) + 1];
	strcpy_s((char*)error, strlen(err) + 1, err);
}

IncorrectDateFormat::IncorrectDateFormat() {
	error = "Incorrect date. Please try again.";
}

SeatOccupied::SeatOccupied(const char* err) {
	if (!error)
		delete[] error;
	error = new char[strlen(err) + 1];
	strcpy_s((char*)error, strlen(err) + 1, err);
}

SeatOccupied::SeatOccupied() {
	error = "Sorry, but this seat is already occupied.";
}

NoInstancesFound::NoInstancesFound(const char* err) {
	if (!error)
		delete[] error;
	error = new char[strlen(err) + 1];
	strcpy_s((char*)error, strlen(err) + 1, err);
}

NumberInName::NumberInName(const char* err) {
	if (!error)
		delete[] error;
	error = new char[strlen(err) + 1];
	strcpy_s((char*)error, strlen(err) + 1, err);
}

SymbolInName::SymbolInName(const char* err) {
	if (!error)
		delete[] error;
	error = new char[strlen(err) + 1];
	strcpy_s((char*)error, strlen(err) + 1, err);
}

UnknownCommand::UnknownCommand(const char* err) {
	if (!error)
		delete[] error;
	error = new char[strlen(err) + 1];
	strcpy_s((char*)error, strlen(err) + 1, err);
}
UnknownCommand::UnknownCommand() {
	error = "Incorrect comand. Please try again.";
}

FileDidntOpen::FileDidntOpen(const char* err) {
	if (!error)
		delete[] error;
	error = new char[strlen(err) + 1];
	strcpy_s((char*)error, strlen(err) + 1, err);
}

void FileDidntOpen::getError() {
	std::cout << msg << " (ERR: " << error << ")" << std::endl;
}

UnknownError::UnknownError(const char* err) {
	if (!error)
		delete[] error;
	error = new char[strlen(err) + 1];
	strcpy_s((char*)error, strlen(err) + 1, err);
}

void UnknownError::getError() {
	std::cout << msg << " (ERR: " << error << ")" << std::endl;
}