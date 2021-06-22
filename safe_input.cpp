#include "error_custom.h"
#include <iostream>
#pragma warning(disable:4996)

const char* type(char* input) {
	char* tp = new char[4];
	strcpy(tp, "nan");
	bool chr = false;
	bool dig = false;
	bool str = false;
	bool fl = false;
	for (int i = 0; i < strlen(input); i++) {
		if (isalpha(input[i]) && !chr) {
			chr = true;
			dig = false;
			continue;
		}
		if (isdigit(input[i])) {
			dig = true;
			continue;
		}
		if (isalpha(input[i]) && chr) {
			str = true;
			continue;
		}
		if (((input[i] == '.') || (input[i] == ',')) && dig) {
			fl = true;
			continue;
		}
	}

	if (str && chr)
		chr = false;
	if (dig && fl)
		dig = false;

	delete[] tp;

	if (str)
		return "str";
	if (dig)
		return "int";
	if (fl)
		return "flt";
	if (chr)
		return "chr";
}


int str2int(char* str) {
	char* tp = new char[3];
	strcpy(tp, type(str));
	if (strcmp(tp, "str") == 0) {
		char* temp = new char[strlen(str) + 1];
		int count = 0;
		for (int i = 0; i < strlen(str); i++)
			if (isdigit(str[i])) {
				temp[count] = str[i];
				count++;
			}
		char* temp2 = new char[count];
		memmove(temp2, temp, count);
		int res = atoi(temp2);
		delete[] temp;
		delete[] temp2;
		return res;
	}
	else
		return atoi(str);
}

double str2dbl(char* str) {
	char* temp_int = NULL;
	char* temp_fl = NULL;
	if (strcmp(type(str), "str") == 0) {
		temp_int = new char[strlen(str) + 1];
		temp_fl = new char[strlen(str) + 1];
		int count = 0;
		int i;
		for (i = 0; i < strlen(str); i++) {
			if (isdigit(str[i])) {
				temp_int[count] = str[i];
				count++;
			}
			if ((str[i] == '.') || (str[i] == ','))
				break;
		}
		count = 0;
		for (i; i < strlen(str); i++)
			if (isdigit(str[i])) {
				temp_fl[count] = str[i];
				count++;
			}
		double mul = 1;
		for (int k = 0; k < count; k++)
			mul = mul / 10;
		double res = atoi(temp_int) + (atoi(temp_fl) * mul);
		delete[] temp_int;
		delete[] temp_fl;
		return res;
	}
	else {
		char* tmp;
		double res = strtod(str, &tmp);
		return res;
	}
}

bool contains_symbol(char*& str) {
	bool res = false;
	for (int i = 0; i < strlen(str); i++)
		if (!isalpha(str[i]))
			res = true;
	return res;
}

int enter_int() {
	char* x = new char[4096];
	while (true) {
		std::cin >> x;
		try {
			if (strcmp(type(x), "int") == 0)
				break;
			else
				throw IllegalInputType("AWAITING_INT");
		}
		catch (IllegalInputType err) {
			std::cout << "Incorrect format. Please try again. (ERR: " << err.getError() << ")" << std::endl;
		}
	}
	return str2int(x);
}

double enter_dbl() {
	char* x = new char[4096];
	double res;
	while (true) {
		std::cin >> x;
		try {
			if (strcmp(type(x), "flt") == 0 || strcmp(type(x), "int") == 0)
				break;
			else
				throw IllegalInputType("AWAITING_DOUBLE");
		}
		catch (IllegalInputType err) {
			std::cout << "Incorrect format. Please try again. (ERR: " << err.getError() << ")" << std::endl;
		}
	}
	res = str2dbl(x);
	delete[] x;
	return res;
}

char* enter_FIO(char*& sname, char*& name, char*& pname) {
	name = new char[4096];
	sname = new char[4096];
	pname = new char[4096];
	while (true) {
		try {
			std::cin >> sname >> name >> pname;
			if (str2int(name) > 0 || str2int(sname) > 0 || str2int(pname) > 0)
				throw NumberInName("NUMBER_IN_NAME");
			if (contains_symbol(name) || contains_symbol(sname) || contains_symbol(pname))
				throw SymbolInName("SYMBOL_IN_NAME");
			break;
		}
		catch (NumberInName err) {
			std::cout << std::endl << "Incorrect format of FIO. Try entering again. (ERR: " << err.getError() << ")" << std::endl << std::endl;
		}
		catch (SymbolInName err) {
			std::cout << std::endl << "Incorrect format of FIO. Try entering again. (ERR: " << err.getError() << ")" << std::endl << std::endl;
		}
	}
}

bool check_date(int d, int m, int y) {
	bool res = true;
	if ((y > 3000 || y < 1900) || (m > 12 || m < 0)) {
		res = false;
		return res;
	}
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		if (d > 31 || d < 0)
			res = false;
		else
			res = true;
	if (m == 4 || m == 6 || m == 9 || m == 11)
		if (d > 30 || d < 0)
			res = false;
		else
			res = true;
	if (m == 2)
		if ((d > 28 && y % 4 != 0) || (d > 29 && y % 4 == 0) || (d < 0))
			res = false;
		else
			res = true;
	return res;
}

void enter_date(int* day, int* month, int* year) {
	while (true) {
		try {
			std::cin >> *day >> *month >> *year;
			if (!check_date(*day, *month, *year))
				throw IncorrectDateFormat();
			break;
		}
		catch (IncorrectDateFormat err) {
			std::cout << err.getError() << std::endl << ">> ";
		}
	}
}

bool binary_yn_choice() {
	char* x = new char[4096];
	while (true) {
		try {
			std::cin >> x;
			if (strcmp(type(x), "chr") != 0)
				throw IllegalInputType("AWAITING_CHAR");
			if (x[0] == 'Y' || x[0] == 'y')
				return true;
			else
				if (x[0] == 'N' || x[0] == 'n')
					return false;
				else
					throw UnknownCommand("UNKW_CMD");
		}
		catch (UnknownCommand err) {
			std::cout << "Unknown command. Please try again" << err.getError() << ")" << std::endl;
		}
		catch (IllegalInputType err) {
			std::cout << "Unknown command. Please try again" << err.getError() << ")" << std::endl;
		}
	}
	delete[] x;
}