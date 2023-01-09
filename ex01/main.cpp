#include "Bureaucrat.hpp"
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
		Bureaucrat b1 = Bureaucrat("test b 1", 30);
		Form f1 = Form("test form 1", 30, 30);
		b1.signForm(f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}