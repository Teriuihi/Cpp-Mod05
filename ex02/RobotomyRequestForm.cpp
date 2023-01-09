#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
		AForm("RobotomyRequestForm", 72, 45), _target("Default") {
	std::cout << "RobotomyRequestForm created with default constructor." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
		AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout <<
		"RobotomyRequestForm created with normal constructor with data:\n" <<
		"\ttarget: [" << _target << "]\n" <<
		std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &f):
		AForm("RobotomyRequestForm", 72, 45), _target(f._target) {
	std::cout <<
		"RobotomyRequestForm created with assignment constructor with data:\n" <<
		"\ttarget: [" << _target << "]\n" <<
		std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &f) {
	_target = f.getTarget();
	std::cout << "RobotomyRequestForm copied with copy operator with data\n" <<
		"\ttarget: [" << _target << "]\n" <<
		std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm deconstructed with data:\n" <<
		"\ttarget: [" << _target << "]\n" <<
		std::endl;
}

void RobotomyRequestForm::finalExecute() {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, 2); // define the range
	if (distr(gen) == 1)
		std::cout << _target+ " was robotomized." << std::endl;
	else
		std::cout << _target+ " was not robotomized."<< std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const {
	return _target;
}

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &dt) {
	o <<
		"RobotomyRequestForm data\n" <<
		"\tname: [" << dt.getName() << "]\n" <<
		"\tsigned: [" << dt.isSigned() << "]\n" <<
		"\trequired sign grade: [" << static_cast<int16_t>(dt.getSignGrade()) << "]\n" <<
		"\trequired execute grade: [" << static_cast<int16_t>(dt.getExecGrade()) << "]\n" <<
		"\ttarget: [" << dt.getTarget() << "]\n";
	return o;
}