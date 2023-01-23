#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <string>
#include <random>

class RobotomyRequestForm: public AForm {
public:
	RobotomyRequestForm();
	explicit RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(RobotomyRequestForm const &);
	RobotomyRequestForm& operator=(RobotomyRequestForm const &);
	~RobotomyRequestForm();
	std::string _target;

	const std::string &getTarget() const;
	void finalExecute();
};
std::ostream& operator<<(std::ostream& o, AForm const& dt);

#endif
