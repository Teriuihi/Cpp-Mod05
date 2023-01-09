#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <ostream>
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
protected:
	AForm();
	AForm(const std::string &name, int signGrade, int execGrade);
	AForm(AForm const &);
	AForm& operator=(AForm const &);
	~AForm();
	virtual void finalExecute() = 0;
public:
	const std::string &getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(Bureaucrat &bureaucrat);
	void execute(Bureaucrat &bureaucrat);


	class GradeTooHighException : public std::exception {
	public:
		AForm &form;
		uint8_t level;
		GradeTooHighException(AForm &, uint8_t);
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		AForm &form;
		uint8_t level;
		GradeTooLowException(AForm &, uint8_t);
		virtual const char *what() const throw();
	};

	class UnsignedException : public std::exception
	{
	public:
		AForm &form;
		Bureaucrat &bureaucrat;
		UnsignedException(AForm &, Bureaucrat &);
		virtual const char *what() const throw();
	};
};
std::ostream& operator<<(std::ostream& o, AForm const& dt);

#endif
