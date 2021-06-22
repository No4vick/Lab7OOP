#pragma once
#include <iostream>
#include <vector>

class fio {
	char* familiya,
		* imya,
		* otchestvo;
	friend class ticket;
public:
	fio();
	~fio();
	char* getSname();
	char* getName();
	char* getPname();

	void setSname(char* str);
	void setName(char* str);
	void setPname(char* str);
	char* getFio();
	void setFio(char* sname, char* name, char* pname);
	fio(const fio& f);
	void operator=(const fio& f);
	bool operator==(fio& b);
	bool operator>(const fio& f);
};

class ticket {
	char* arrival;
	double price;
public:
	fio name;
	ticket();
	~ticket();
	void setArrival(char* str);
	void setPrice(double prc);
	char* getArrival();
	double getPrice();
	ticket(char* sname, char* name, char* pname, char* ptf = (char*)"Nowhere", char* ptt = (char*)"Nowhere", int prc = 0);
	ticket(const ticket& tk);
	void operator=(const ticket& tk);
	bool operator==(fio& fio);
	static void filter_fio(std::vector<ticket>& tks);
	void print(const char* param = "Nothing");
	void enter_inst(int n);
	friend std::istream& operator>>(std::istream& is, ticket& tk);
	friend std::ostream& operator<<(std::ostream& os, ticket& tk);
};


int menu(int n);
void console_continue();
void table(std::vector<ticket>& tickets);
void filefill(ticket& tr, int n);
void filerewrite(std::vector<ticket>& tickets);
void fileread(std::vector<ticket> &tickets);
void sort_alphabetically(std::vector<ticket> tickets);