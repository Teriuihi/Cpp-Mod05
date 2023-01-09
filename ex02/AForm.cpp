#include "AForm.hpp"

Form::Form(): _name("Default"), _signed(false), _signGrade(1), _execGrade(1) {
	std::cout << "Form created with default constructor." << std::endl;
}

Form::Form(const std::string &name, const int signGrade, const int execGrade)
			: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1)
		throw Form::GradeTooHighException(*this, signGrade);
	else if (signGrade > 150)
		throw Form::GradeTooLowException(*this, signGrade);
	if (execGrade < 1)
		throw Form::GradeTooHighException(*this, execGrade);
	else if (execGrade > 150)
		throw Form::GradeTooLowException(*this, execGrade);
	std::cout <<
		"Form created with normal constructor with data:\n" <<
		"\tname: [" << _name << "]\n" <<
		"\tsigned: [" << _signed << "]\n" <<
		"\trequired sign grade: [" << static_cast<int16_t>(_signGrade) << "]\n" <<
		"\trequired execute grade: [" << static_cast<int16_t>(_execGrade) << "]" <<
		std::endl;
}

Form::Form(const Form &f) : _name(f.getName()), _signed(f.isSigned()), _signGrade(f.getSignGrade()), _execGrade(
		f.getExecGrade()) {
	std::cout <<
		"Form created with assignment constructor with data:\n" <<
		"\tname: [" << _name << "]\n" <<
		"\tsigned: [" << _signed << "]\n" <<
		"\trequired sign grade: [" << static_cast<int16_t>(_signGrade) << "]\n" <<
		"\trequired execute grade: [" << static_cast<int16_t>(_execGrade) << "]" <<
		std::endl;
}

Form &Form::operator=(const Form &f) {
	_signed = f.isSigned();
	std::cout <<
		"Form copied with copy operator with data:\n" <<
		"\tname: [" << _name << "]\n" <<
		"\tsigned: [" << _signed << "]\n" <<
		"\trequired sign grade: [" << static_cast<int16_t>(_signGrade) << "]\n" <<
		"\trequired execute grade: [" << static_cast<int16_t>(_execGrade) << "]" <<
		std::endl;
	return *this;
}

Form::~Form() {
	std::cout << "Form deconstructed with data:\n" <<
		"\tname: [" << _name << "]\n" <<
		"\tsigned: [" << _signed << "]\n" <<
		"\trequired sign grade: [" << static_cast<int16_t>(_signGrade) << "]\n" <<
		"\trequired execute grade: [" << static_cast<int16_t>(_execGrade) << "]" <<
		std::endl;
}

const std::string &Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _signed;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException(*this, _signGrade);
	_signed = true;
}

Form::GradeTooHighException::GradeTooHighException(Form &form, uint8_t level) : form(form), level(level) {

}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}


Form::GradeTooLowException::GradeTooLowException(Form &form, uint8_t level) : form(form), level(level){

}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &o, const Form &dt) {
	o <<
		"Form data\n" <<
		"\tname: [" << dt.getName() << "]\n" <<
		"\tsigned: [" << dt.isSigned() << "]\n" <<
		"\trequired sign grade: [" << static_cast<int16_t>(dt.getSignGrade()) << "]\n" <<
		"\trequired execute grade: [" << static_cast<int16_t>(dt.getExecGrade()) << "]\n";
	return o;
}