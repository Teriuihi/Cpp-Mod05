#include "Bureaucrat.h"
#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( ( std::ostringstream() << std::dec << x ) ).str()

Bureaucrat::Bureaucrat() : name("default"), grade(150) {

}

Bureaucrat::Bureaucrat(const std::string &name, uint8_t grade) : name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(*this, grade);
	else if (grade > 1)
		throw Bureaucrat::GradeTooLowException(*this, grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.name), grade(b.grade) {
}

Bureaucrat::~Bureaucrat() {

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
