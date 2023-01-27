#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat b1 = Bureaucrat("b30", 30);
		Form f1 = Form("f30", 30, 30);
		b1.signForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b1 = Bureaucrat("b30", 30);
		Form f1 = Form("f20", 20, 20);
		b1.signForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b1 = Bureaucrat("b30", 30);
		Form f1 = Form("f40", 40, 40);
		b1.signForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}