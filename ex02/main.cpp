#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void printGrade(Bureaucrat &bureaucrat) {
	std::cout
	<< bureaucrat.getName()
	<< " grade: "
	<< static_cast<int16_t>(bureaucrat.getGrade())
	<< std::endl;
}

int main() {
	try {
		Bureaucrat b1 = Bureaucrat("b30", 30);
		ShrubberyCreationForm f1 = ShrubberyCreationForm("one");
		b1.signForm(f1);
		b1.executeForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b1 = Bureaucrat("b30", 30);
		ShrubberyCreationForm f1 = ShrubberyCreationForm("two");
		b1.signForm(f1);
		b1.executeForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b1 = Bureaucrat("b30", 30);
		ShrubberyCreationForm f1 = ShrubberyCreationForm("three");
		b1.signForm(f1);
		b1.executeForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}