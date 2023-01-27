#include "Intern.hpp"
#include "AForm.hpp"

void runForm(AForm *form, Bureaucrat &bureaucrat) {
	if (form == NULL)
		return;
	form->beSigned(bureaucrat);
	form->execute(bureaucrat);
}

int main() {
	Bureaucrat bob = Bureaucrat("bob", 1);
	Intern steve = Intern();

	try {
		runForm(steve.makeForm("presidential pardon form", "One"), bob);
		runForm(steve.makeForm("robotomy request form", "Two"), bob);
		runForm(steve.makeForm("shrubbery creation form", "Three"), bob);
		runForm(steve.makeForm("shrubbery creation form ", "Four"), bob);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}