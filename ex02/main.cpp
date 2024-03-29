#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
		RobotomyRequestForm f1 = RobotomyRequestForm("two");
		b1.signForm(f1);
		b1.executeForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b1 = Bureaucrat("b30", 1);
		PresidentialPardonForm f1 = PresidentialPardonForm("three");
		b1.signForm(f1);
		b1.executeForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b1 = Bureaucrat("b20", 20);
		PresidentialPardonForm f1 = PresidentialPardonForm("four");
		b1.signForm(f1);
		b1.executeForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b1 = Bureaucrat("b100", 100);
		PresidentialPardonForm f1 = PresidentialPardonForm("three");
		b1.signForm(f1);
		b1.executeForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}