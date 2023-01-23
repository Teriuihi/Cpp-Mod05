#include "AForm.hpp"

AForm::AForm(): _name("Default"), _signed(false), _signGrade(1), _execGrade(1) {
	std::cout << "AForm created with default constructor." << std::endl;
}

AForm::AForm(const std::string &name, const int signGrade, const int execGrade)
			: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1)
		throw AForm::GradeTooHighException(*this, signGrade);
	else if (signGrade > 150)
		throw AForm::GradeTooLowException(*this, signGrade);
	if (execGrade < 1)
		throw AForm::GradeTooHighException(*this, execGrade);
	else if (execGrade > 150)
		throw AForm::GradeTooLowException(*this, execGrade);
	std::cout <<
		"AForm created with normal constructor with data:\n" <<
		"\tname: [" << _name << "]\n" <<
		"\tsigned: [" << _signed << "]\n" <<
		"\trequired sign grade: [" << static_cast<int16_t>(_signGrade) << "]\n" <<
		"\trequired execute grade: [" << static_cast<int16_t>(_execGrade) << "]" <<
		std::endl;
}

AForm::AForm(const AForm &f) : _name(f.getName()), _signed(f.isSigned()), _signGrade(f.getSignGrade()), _execGrade(
		f.getExecGrade()) {
	std::cout <<
		"AForm created with assignment constructor with data:\n" <<
		"\tname: [" << _name << "]\n" <<
		"\tsigned: [" << _signed << "]\n" <<
		"\trequired sign grade: [" << static_cast<int16_t>(_signGrade) << "]\n" <<
		"\trequired execute grade: [" << static_cast<int16_t>(_execGrade) << "]" <<
		std::endl;
}

AForm &AForm::operator=(const AForm &f) {
	_signed = f.isSigned();
	std::cout <<
		"AForm copied with copy operator with data:\n" <<
		"\tname: [" << _name << "]\n" <<
		"\tsigned: [" << _signed << "]\n" <<
		"\trequired sign grade: [" << static_cast<int16_t>(_signGrade) << "]\n" <<
		"\trequired execute grade: [" << static_cast<int16_t>(_execGrade) << "]" <<
		std::endl;
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm deconstructed with data:\n" <<
		"\tname: [" << _name << "]\n" <<
		"\tsigned: [" << _signed << "]\n" <<
		"\trequired sign grade: [" << static_cast<int16_t>(_signGrade) << "]\n" <<
		"\trequired execute grade: [" << static_cast<int16_t>(_execGrade) << "]" <<
		std::endl;
}

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _signed;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException(*this, _signGrade);
	_signed = true;
}

void AForm::execute(Bureaucrat &bureaucrat) {
	if (!isSigned())
		throw AForm::UnsignedException(*this, bureaucrat);
	if (bureaucrat.getGrade() > _execGrade)
		throw AForm::GradeTooLowException(*this, _execGrade);
	finalExecute();
}

AForm::GradeTooHighException::GradeTooHighException(AForm &form, uint8_t level) :
		form(form), level(level) {

}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}


AForm::GradeTooLowException::GradeTooLowException(AForm &form, uint8_t level) :
		form(form), level(level) {

}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &o, const AForm &dt) {
	o <<
		"AForm data\n" <<
		"\tname: [" << dt.getName() << "]\n" <<
		"\tsigned: [" << dt.isSigned() << "]\n" <<
		"\trequired sign grade: [" << static_cast<int16_t>(dt.getSignGrade()) << "]\n" <<
		"\trequired execute grade: [" << static_cast<int16_t>(dt.getExecGrade()) << "]\n";
	return o;
}

const char *AForm::UnsignedException::what() const throw() {
	return "This form has not been signed yet, so it can not be executed.";
}

AForm::UnsignedException::UnsignedException(AForm &form, Bureaucrat &bureaucrat) :
		form(form), bureaucrat(bureaucrat) {

}
