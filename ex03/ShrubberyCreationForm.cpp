#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
		AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
	std::cout << "ShrubberyCreationForm created with default constructor." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
		AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout <<
		"ShrubberyCreationForm created with normal constructor with data:\n" <<
		"\ttarget: [" << _target << "]\n" <<
		std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &f):
		AForm("ShrubberyCreationForm", 145, 137), _target(f._target) {
	std::cout <<
		"ShrubberyCreationForm created with assignment constructor with data:\n" <<
		"\ttarget: [" << _target << "]\n" <<
		std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &f) {
	_target = f.getTarget();
	std::cout << "ShrubberyCreationForm copied with copy operator with data\n" <<
		"\ttarget: [" << _target << "]\n" <<
		std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm deconstructed with data:\n" <<
		"\ttarget: [" << _target << "]\n" <<
		std::endl;
}

void ShrubberyCreationForm::createFile(const std::string &fileName) {
	this->ofs.open(fileName);
	if (!ofs.is_open()) {
		std::cout << "Couldn't create file: [" << fileName << "]." << std::endl;
		return;
	}
}

void ShrubberyCreationForm::finalExecute() {
	createFile("tree.txt");
	ofs << "                                                         ." << std::endl;
	ofs << "                                              .         ;" << std::endl;
	ofs << "                 .              .              ;%     ;;" << std::endl;
	ofs << "                   ,           ,                :;%  %;" << std::endl;
	ofs << "                    :         ;                   :;%;'     .," << std::endl;
	ofs << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
	ofs << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	ofs << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
	ofs << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	ofs << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	ofs << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	ofs << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
	ofs << "                      `@%:.  :;%.         ;@@%;'" << std::endl;
	ofs << "                        `@%.  `;@%.      ;@@%;" << std::endl;
	ofs << "                          `@%%. `@%%    ;@@%;" << std::endl;
	ofs << "                            ;@%. :@%%  %@@%;" << std::endl;
	ofs << "                              %@bd%%%bd%%:;" << std::endl;
	ofs << "                                #@%%%%%:;;" << std::endl;
	ofs << "                                %@@%%%::;" << std::endl;
	ofs << "                                %@@@%(o);  . '" << std::endl;
	ofs << "                                %@@@o%;:(.,'" << std::endl;
	ofs << "                            `.. %@@@o%::;" << std::endl;
	ofs << "                               `)@@@o%::;" << std::endl;
	ofs << "                                %@@(o)::;" << std::endl;
	ofs << "                               .%@@@@%::;" << std::endl;
	ofs << "                               ;%@@@@%::;." << std::endl;
	ofs << "                              ;%@@@@%%:;;;. " << std::endl;
	ofs << "                          ...;%@@@@@%%:;;;;," << std::endl;
	ofs << "credits: Gilo97 (taken from https://ascii.co.uk/art/tree)" << std::endl;
	ofs.close();
}

const std::string &ShrubberyCreationForm::getTarget() const {
	return _target;
}

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &dt) {
	o <<
		"ShrubberyCreationForm data\n" <<
		"\tname: [" << dt.getName() << "]\n" <<
		"\tsigned: [" << dt.isSigned() << "]\n" <<
		"\trequired sign grade: [" << static_cast<int16_t>(dt.getSignGrade()) << "]\n" <<
		"\trequired execute grade: [" << static_cast<int16_t>(dt.getExecGrade()) << "]\n" <<
		"\ttarget: [" << dt.getTarget() << "]\n";
	return o;
}