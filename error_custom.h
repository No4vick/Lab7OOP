#pragma once

class Errors {
protected: 
	const char* error;
public:
	const char* getError();
};

class IllegalInputType : public Errors {
public:
	IllegalInputType(const char* err);
	IllegalInputType();
};

class IncorrectDateFormat : public Errors {
public:
	IncorrectDateFormat(const char* err);
	IncorrectDateFormat();
};

class SeatOccupied : public Errors {
public:
	SeatOccupied(const char* err);
	SeatOccupied();
};

class NoInstancesFound : public Errors {
public:
	NoInstancesFound(const char* err);
};

class NumberInName : public Errors {
public:
	NumberInName(const char* err);
};

class SymbolInName : public Errors {
public:
	SymbolInName(const char* err);
};

class UnknownCommand : public Errors {
public:
	UnknownCommand(const char* err);
	UnknownCommand();
};

class FileDidntOpen : public Errors {
	const char* msg = "File didn't open.";
public:
	FileDidntOpen(const char* err);
	void getError();
};

class UnknownError : public Errors {
	const char* msg = "Unknown Error.";
public:
	UnknownError(const char* err);
	void getError();
};