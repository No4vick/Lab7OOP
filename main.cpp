#include <iostream>
#include "funcs.h"
#include "error_custom.h"
#include "safe_input.h"

int main() {
	std::vector<ticket> tickets;
	int x, n = 0;
	ticket tmp_tk;
	bool exit = false;
	fileread(tickets);
	while (!exit) {
		x = menu(tickets.size());
		switch (x) {
		case 1: system("cls");
			tmp_tk.enter_inst(tickets.size());
			tickets.push_back(tmp_tk);
			console_continue();
			break;
		case 2: system("cls");
			std::cout << "You are about to delete the instance\n";
			std::cout << tickets.back();
			std::cout << "Do you wish to continue? (y/n)\n";
			if (binary_yn_choice()) {
				tickets.pop_back();
				filerewrite(tickets);
			}
			console_continue();
			break;
		case 3: system("cls");
			table(tickets);
			console_continue();
			break;
		case 4: system("cls");
			ticket::filter_fio(tickets);
			console_continue();
			break;
		case 5: system("cls");
			sort_alphabetically(tickets);
			console_continue();
			break;
		case 6: std::cout << "Exited." << std::endl;
			exit = true;
			break;
		default: std::cout << "Unknown command. Please try again. (ERR: UNKW_CMD)" << std::endl;
			console_continue();
			break;
		}
	}
}