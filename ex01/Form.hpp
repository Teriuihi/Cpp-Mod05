#ifndef FORM_H
#define FORM_H
#include <string>
#include <ostream>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
public:
	Form();
	Form(const std::string &name, int signGrade, int execGrade);
	Form(Form const &);
	Form& operator=(Form const &);
	~Form();
	const std::string &getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		Form &form;
		uint8_t level;
		GradeTooHighException(Form &, uint8_t);
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		Form &form;
		uint8_t level;
		GradeTooLowException(Form &, uint8_t);
		virtual const char *what() const throw();
	};
};
std::ostream& operator<<(std::ostream& o, Form const& dt);

#endif
