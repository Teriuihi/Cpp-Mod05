#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern() {
	std::cout << "Intern created with default constructor." << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern deconstructed." << std::endl;
}

AForm* Intern::makeForm(std::string name, std::string target) {
	static FormStorage formStorageArray[] = {
			{"presidential pardon form", &createPresidentialPardonForm},
			{"robotomy request form", &createRobotomyRequestForm},
			{"shrubbery creation form", &createShrubberyCreationForm}
	};
	for (int i = 0; i < 3; i++) {
		if (formStorageArray[i].formName == name) {
			std::cout << "Intern is creating [" << name << "] form." << std::endl;
			return formStorageArray[i].formConstructor(target);
		}
	}
	std::cout << "Intern was unable to create form [" << name << "] because it doesn't know where to find it..." << std::endl;
	return NULL;
}

AForm* Intern::createPresidentialPardonForm(std::string const & target) {
	return new PresidentialPardonForm(target);
}
AForm* Intern::createRobotomyRequestForm(std::string const & target) {
	return new RobotomyRequestForm(target);
}
AForm* Intern::createShrubberyCreationForm(std::string const & target) {
	return new ShrubberyCreationForm(target);
}