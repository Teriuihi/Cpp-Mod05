#include "Bureaucrat.h"
#include <iostream>

void printGrade(Bureaucrat &bureaucrat) {
	std::cout
	<< bureaucrat.getName()
	<< " grade: "
	<< static_cast<int16_t>(bureaucrat.getGrade())
	<< std::endl;
}

int main() {
	try { Bureaucrat("test1", 0); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { Bureaucrat("test2", 151); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try {
		Bureaucrat a = Bureaucrat("test3", 150);
		a.increment();
		a.decrement();
		printGrade(a);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat a = Bureaucrat("test4", 149);
		Bureaucrat b = Bureaucrat("test5", 1);
		a.increment();
		a.decrement();
		b.decrement();
		printGrade(a);
		printGrade(b);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat a = Bureaucrat("test6", 1);
		a.decrement();
		printGrade(a);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}