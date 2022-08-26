#include "Bureaucrat.h"
#include <iostream>

int main() {
	try {
		Bureaucrat("test", 0);
		Bureaucrat a = Bureaucrat("test", 150);
		Bureaucrat b = Bureaucrat("test", 1);
		Bureaucrat("test", 151);
		a.increment();
		a.decrement();
		b.decrement();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}