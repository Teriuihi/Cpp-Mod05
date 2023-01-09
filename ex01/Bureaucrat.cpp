#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
	std::cout << "Bureaucrat created with default constructor." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, uint8_t grade) : name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(*this, grade);
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException(*this, grade);
	this->grade = grade;
	std::cout << "Bureaucrat created with name [" << name << "] and grade [" << static_cast<int16_t>(grade)
		<< "] using the normal constructor." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.name), grade(b.grade) {
	std::cout << "Bureaucrat created with name [" << name << "] and grade [" << static_cast<int16_t>(grade)
			  << "] using the assignment constructor." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b) {
	this->grade = b.grade;
	std::cout << "Bureaucrat copied with name [" << name << "] and grade [" << static_cast<int16_t>(grade)
			  << "] using the assignment operator." << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat deconstructed with name [" << name << "] and grade [" << static_cast<int16_t>(grade) << "]." << std::endl;
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

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(this);
	} catch (Form::GradeTooLowException &e) {
		std::cout << name << " couldn't sign form [" << form.getName() << "] because " << name << "'s grade is too low.";
		return;
	}
	std::cout << name << " signed form [" << form.getName() << "]";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &dt) {
	o << dt.getName() << ", bureaucrat grade " << static_cast<int16_t>(dt.getGrade());
	return o;
}
