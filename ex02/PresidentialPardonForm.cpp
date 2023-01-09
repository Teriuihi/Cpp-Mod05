#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
		AForm("PresidentialPardonForm", 25, 5), _target("Default") {
	std::cout << "PresidentialPardonForm created with default constructor." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
		AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout <<
		"PresidentialPardonForm created with normal constructor with data:\n" <<
		"\ttarget: [" << _target << "]\n" <<
		std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &f):
		AForm("PresidentialPardonForm", 25, 5), _target(f._target) {
	std::cout <<
		"PresidentialPardonForm created with assignment constructor with data:\n" <<
		"\ttarget: [" << _target << "]\n" <<
		std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &f) {
	_target = f.getTarget();
	std::cout << "PresidentialPardonForm copied with copy operator with data\n" <<
		"\ttarget: [" << _target << "]\n" <<
		std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm deconstructed with data:\n" <<
		"\ttarget: [" << _target << "]\n" <<
		std::endl;
}

void PresidentialPardonForm::finalExecute() {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const {
	return _target;
}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &dt) {
	o <<
		"PresidentialPardonForm data\n" <<
		"\tname: [" << dt.getName() << "]\n" <<
		"\tsigned: [" << dt.isSigned() << "]\n" <<
		"\trequired sign grade: [" << static_cast<int16_t>(dt.getSignGrade()) << "]\n" <<
		"\trequired execute grade: [" << static_cast<int16_t>(dt.getExecGrade()) << "]\n" <<
		"\ttarget: [" << dt.getTarget() << "]\n";
	return o;
}