#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include <string>
#include <random>

class PresidentialPardonForm: public AForm {
public:
	PresidentialPardonForm();
	explicit PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(PresidentialPardonForm const &);
	PresidentialPardonForm& operator=(PresidentialPardonForm const &);
	~PresidentialPardonForm();
	std::string _target;

	const std::string &getTarget() const;
	void finalExecute();
};
std::ostream& operator<<(std::ostream& o, AForm const& dt);

#endif
