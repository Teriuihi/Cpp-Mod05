#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <ostream>
#include <iostream>
#include "AForm.hpp"
class AForm;

class Bureaucrat {
private:
	const std::string name;
	uint8_t grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, uint8_t grade);
	Bureaucrat(Bureaucrat const &);
	Bureaucrat& operator=(Bureaucrat const &);
	~Bureaucrat();

	const std::string &getName() const;

	unsigned char getGrade() const;

	class GradeTooHighException : public std::exception {
	public:
		Bureaucrat &b;
		uint8_t level;
		GradeTooHighException(Bureaucrat &, uint8_t);
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		Bureaucrat &b;
		uint8_t level;
		GradeTooLowException(Bureaucrat &, uint8_t);
		virtual const char *what() const throw();
	};

	void increment();

	void decrement();
	void signForm(AForm &form);
	void executeForm(AForm &form);
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& dt);
#endif
