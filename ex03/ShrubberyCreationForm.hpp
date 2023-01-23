#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <string>
#include <fstream>

class ShrubberyCreationForm: public AForm {
private:
	std::ofstream ofs;
	void createFile(const std::string& fileName);
public:
	ShrubberyCreationForm();
	explicit ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const &);
	~ShrubberyCreationForm();
	std::string _target;

	const std::string &getTarget() const;
	void finalExecute();
};
std::ostream& operator<<(std::ostream& o, AForm const& dt);

#endif
