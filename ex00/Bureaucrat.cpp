#include <iostream>
#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
	std::cout << "Bureaucrat created with default constructor." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, uint8_t grade) : name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(*this, grade);
	else if (grade > 1)
		throw Bureaucrat::GradeTooLowException(*this, grade);
	this->grade = grade;
	std::cout << "Bureaucrat created with name [" << name << "] and grade [" << grade
		<< "] using the normal constructor." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.name), grade(b.grade) {
	std::cout << "Bureaucrat created with name [" << name << "] and grade [" << grade
			  << "] using the assignment constructor." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b) {
	this->grade = b.grade;
	std::cout << "Bureaucrat copied with name [" << name << "] and grade [" << grade
			  << "] using the assignment operator." << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat deconstructed with name [" << name << "] and grade [" << grade << "]." << std::endl;
}

const std::string &Bureaucrat::getName() const {
	return name;
}

uint8_t Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::increment() {
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException(*this, grade);
	grade--;
}

void Bureaucrat::decrement() {
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException(*this, grade);
	grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

Bureaucrat::GradeTooHighException::GradeTooHighException(Bureaucrat &b, uint8_t level) : b(b), level(level) {

}

Bureaucrat::GradeTooLowException::GradeTooLowException(Bureaucrat &b, uint8_t level) : b(b), level(level){

}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &dt) {
	o << dt.getName() << ", bureaucrat grade " << dt.getGrade();
	return o;
}
