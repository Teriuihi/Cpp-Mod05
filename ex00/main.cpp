#include "Bureaucrat.h"
#include <iostream>

int main() {
	try {
		Bureaucrat("test", 0);
		Bureaucrat a = Bureaucrat("test", 150);
		Bureaucrat("test", 151);
		a.increment();
		a.decrement();
        std::cout << "A grade: " << a.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

    try {
        Bureaucrat a = Bureaucrat("test", 150);
        Bureaucrat b = Bureaucrat("test", 1);
        a.increment();
        a.decrement();
        b.decrement();
        std::cout << "A grade: " << a.getGrade() << std::endl;
        std::cout << "B grade: " << b.getGrade() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b = Bureaucrat("test", 1);
        b.decrement();
        std::cout << "B grade: " << b.getGrade() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}