#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
	Intern();
	~Intern();
	AForm* makeForm(std::string name, std::string target);
private:
	typedef AForm* (*formConstructor)(std::string target);
	typedef struct {
		std::string formName;
		AForm *(*formConstructor)(const std::string &);
	} FormStorage;

	static AForm* createPresidentialPardonForm(std::string const & target);
	static AForm* createRobotomyRequestForm(std::string const & target);
	static AForm* createShrubberyCreationForm(std::string const & target);
};


#endif
