#pragma once
const char* type(char* input);
int str2int(char* str);
double str2dbl(char* str);
bool contains_symbol(char*& str);
int enter_int();
double enter_dbl();
char* enter_FIO(char*& sname, char*& name, char*& pname);
bool check_date(int d, int m, int y);
void enter_date(int* day, int* month, int* year);
bool binary_yn_choice();