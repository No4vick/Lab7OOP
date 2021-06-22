#include "funcs.h"
#include "error_custom.h"
#include "safe_input.h"
#include <iomanip>
#include <algorithm>
#include <fstream>
#define maxl 4096
#pragma warning(disable:4996)

// FIO Methods:

fio::fio() {
	familiya = new char[maxl];
	strcpy(familiya, "Error");
	imya = new char[maxl];
	strcpy(imya, "Error");
	otchestvo = new char[maxl];
	strcpy(otchestvo, "Error");
};
fio::~fio() {
	delete[] familiya;
	delete[] imya;
	delete[] otchestvo;
}
char* fio::getSname() { return familiya; }
char* fio::getName() { return imya; }
char* fio::getPname() { return otchestvo; }
bool fio::operator==(fio& b) {
	if (strcmp(familiya, b.familiya) == 0 && strcmp(imya, b.imya) == 0 && strcmp(otchestvo, b.otchestvo) == 0)
		return true;
	else
		return false;
}

void fio::setSname(char* str) {
	if (familiya)
		delete[] familiya;
	familiya = new char[strlen(str) + 1];
	//strcpy(familiya, str);
	strcpy_s(familiya, strlen(str) + 1, str);
}
void fio::setName(char* str) {
	if (imya)
		delete[] imya;
	imya = new char[strlen(str) + 1];
	strcpy_s(imya, strlen(str) + 1, str);
}
void fio::setPname(char* str) {
	if (otchestvo)
		delete[] otchestvo;
	otchestvo = new char[strlen(str) + 1];
	//strcpy(otchestvo, str);
	strcpy_s(otchestvo, strlen(str) + 1, str);
}

char* fio::getFio() {
	char* res = new char[strlen(familiya) + strlen(imya) + strlen(otchestvo) + 1 + 2];
	strcpy(res, familiya);
	strcat(res, " ");
	strcat(res, imya);
	strcat(res, " ");
	strcat(res, otchestvo);
	return res;
}
void fio::setFio(char* sname, char* name, char* pname) {
	setSname(sname);
	setName(name);
	setPname(pname);
}
fio::fio(const fio& f) {
	setFio(f.familiya, f.imya, f.otchestvo);
}
void fio::operator=(const fio& f) {
	setFio(f.familiya, f.imya, f.otchestvo);
}
bool fio::operator>(const fio& f) {
	if (familiya[0] > f.familiya[0])
		return true;
	else
		return false;

	if (familiya[0] == f.familiya[0] && familiya[1] > f.familiya[1])
		return true;
	else
		return false;

	if (familiya[0] == f.familiya[0] && familiya[1] == f.familiya[1] && familiya[2] > f.familiya[2])
		return true;
	else
		return false;
}

//Ticket Methods:

ticket::ticket() {
	arrival = new char[maxl];
	strcpy(arrival, "World Anxiety");
	price = 0;
}

ticket::~ticket() {
	delete[] arrival;
}

void ticket::setArrival(char* str) {//, const char* param = "Old") {
	if (!arrival)
		delete[] arrival;
	arrival = new char[strlen(str) + 1];
	strcpy(arrival, str);
}

char* ticket::getArrival() { return arrival; }

void ticket::setPrice(double prc){
	price = prc;
}

double ticket::getPrice() { return price; }

ticket::ticket(char* sname, char* name, char* pname, char* ptf, char* ptt, int prc) {
	setArrival(ptt);
	price = prc;
}
ticket::ticket(const ticket& tk) {
	name = tk.name;
	setArrival(tk.arrival);
	price = tk.price;
}
void ticket::operator=(const ticket& tk) {
	name = tk.name;
	setArrival(tk.arrival);
	price = tk.price;
}

bool ticket::operator==(fio &fio) {
	if (name == fio)
		return true;
	else
		return false;
}

void ticket::print(const char* param) {
	std::cout << "FIO: " << name.getFio() << std::endl;
	if (strcmp(param, "Arrival") == 0)
		std::cout << "->Arrival: " << arrival << std::endl;
	else
		std::cout << "Arrival: " << arrival << std::endl;
	std::cout << "Price: " << price << std::endl;
}

void console_continue() {
	system("pause");
	system("cls");
}

std::istream& operator>>(std::istream& cin, ticket& tk) {
	char* buff;
	char* nm;
	char* pnm;

	std::cout << "Enter FIO: ";
	enter_FIO(buff, nm, pnm);
	tk.name.setFio(buff, nm, pnm);

	buff = new char[maxl];
	std::cout << "Enter point of arrival: ";
	cin >> buff;
	tk.setArrival(buff);
	std::cout << "Enter price: ";
	double price = enter_dbl();
	tk.setPrice(price);

	//tk.count++;

	delete[] buff;
	delete[] nm;
	delete[] pnm;
	return cin;
}

std::ostream& operator<<(std::ostream& os, ticket& tk) {
	tk.print();
	return os;
}

void ticket::enter_inst(int n) {
	std::cin >> *this;
	filefill(*this, n + 1);
}


void ticket::filter_fio(std::vector<ticket>& tks) {
	char* buff;
	char* sname;
	char* pname;
	fio tmp;
	std::cout << "Enter FIO you want to find: ";
	enter_FIO(buff, sname, pname);
	tmp.setFio(buff, sname, pname);
	//std::cout << "Found " << std::count_if(tks.begin(), tks.end(), ) << " instances:" << std::endl;
	for (ticket i : tks) {
		if (i.name == tmp)
			std::cout << i << std::endl;
	}
}

// General functions

int menu(int n) {
	std::cout << "              /Menu/" << std::endl;
	std::cout << "Add new instance" << std::setw(23) << std::setfill('.') << "| 1 |" << std::endl;
	std::cout << "Delete the last instance" << std::setw(15) << std::setfill('.') << "| 2 |" << std::endl;
	std::cout << "Print the database" << std::setw(21) << "| 3 |" << std::endl;
	std::cout << "Find ticket by name" << std::setw(20) << "| 4 |" << std::endl;
	//std::cout << "Filter by price" << std::setw(24) << "| 4 |" << std::endl;
	std::cout << "Sort departure alphabetically" << std::setw(10) << "| 5 |" << std::endl;
	std::cout << "Exit" << std::setw(35) << "| 6 |" << std::endl;
	//cout << "---------------------------------" << endl;
	std::cout << std::endl << "Storage: " << n << std::endl;
	std::cout << std::endl;
	std::cout << "Enter the function number: ";
	int res = enter_int();
	std::cout << std::setfill(' ') << std::endl;

	return res;
}

void table(std::vector<ticket> &tks) {
	try {
		if (tks.size() < 0)
			throw NoInstancesFound("NO_INST");
		std::cout << std::left << std::setw(25) << "Name" << std::setw(20) << "Arrival" << std::setw(14) << "Price" << std::endl;
		std::cout << "-------------------------------------------------------\n";
		for (int i = 0; i < tks.size(); i++)
			std::cout << std::setw(25) << tks[i].name.getFio() << std::setw(20) << tks[i].getArrival() << std::setw(14) << \
			tks[i].getPrice() << std::endl;
		std::cout << std::endl << "Total: " << tks.size() << std::endl << std::endl << std::right;
	}
	catch (NoInstancesFound err) {
		std::cout << "Nothing to show. (ERR: " << err.getError() << ")" << std::endl;
	}
}

void filerewrite(std::vector<ticket> &tickets) {
	std::ofstream fout;
	fout.open("db.txt", std::ios::trunc);
	for (int i = 0; i < tickets.size(); i++){
		if (!fout.is_open())
			throw FileDidntOpen("FILE_NOT_OPENED");
		if (i > 0)
			fout << std::endl;
		fout << i + 1 << ". FIO: " << tickets[i].name.getFio()\
			<< " Arrival: " << tickets[i].getArrival() << " Price: " << tickets[i].getPrice();
	}
	fout.close();
}

void fileread(std::vector<ticket> &tickets) {
	std::ifstream fin;
	int n = 0;
	ticket tmp_tk;
	fin.open("db.txt", std::ios::in);
	if (!fin.is_open()) {
		throw FileDidntOpen("FILE_NOT_OPENED");
	}
	char* s = new char[maxl];
	char* buff = new char[maxl];
	char* name = new char[maxl];
	char* ot4 = new char[maxl];
	char* arr = new char[maxl];
	double price;
	while (!fin.eof()) {
		fin >> n >> s;
		if (n < 1) {
			n = 0;
			break;
		}
		fin >> s >> buff >> name >> ot4 >> s >> arr >> s >> price;
		tmp_tk.name.setFio(buff, name, ot4);
		tmp_tk.setArrival(arr);
		tmp_tk.setPrice(price);
		tickets.push_back(tmp_tk);
	}
	fin.close();
	//for (int i = 0; i < n; i++)
	//	tickets[i].print();
	delete[] arr;
	delete[] buff;
	delete[] name;
	delete[] ot4;
	delete[] s;
	//return n;
}

void filefill(ticket& tr, int n) {
	std::ofstream fout;
	fout.open("db.txt", std::ios_base::app);
	if (!fout.is_open())
		throw FileDidntOpen("FILE_NOT_OPENED");
	if (n > 0)
		fout << std::endl;
	fout << n << ". FIO: " << tr.name.getFio()\
		<< " Arrival: " << tr.getArrival() << " Price: " << tr.getPrice();
	fout.close();
}

/*bool comptks(ticket& x, ticket& y) {
	if (x.name > y.name)
		return true;
	else
		return false; 
}*/

void sort_alphabetically(std::vector<ticket> tickets) {
	std::sort(tickets.begin(), tickets.end(), [](ticket& x, ticket& y) {
		if (y.name > x.name)
			return true;
		else
			return false;
		});
	std::cout << "As sorted alphabetically: " << std::endl << std::endl;
	for (ticket i : tickets)
		std::cout << i << std::endl;
}