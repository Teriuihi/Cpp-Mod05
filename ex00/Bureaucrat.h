#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <string>
#include <ostream>

class Bureaucrat {
private:
	const std::string name;
	uint8_t grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, uint8_t grade);
	Bureaucrat(Bureaucrat const &);
	~Bureaucrat();

	const std::string &getName() const;

	unsigned char getGrade() const;

	class GradeTooHighException : public std::exception {
	public:
		Bureaucrat &b;
		uint8_t level;
		GradeTooHighException(Bureaucrat &, uint8_t);
		const char *what() const _NOEXCEPT;
	};
	class GradeTooLowException : public std::exception
	{
	public:
		Bureaucrat &b;
		uint8_t level;
		GradeTooLowException(Bureaucrat &, uint8_t);
		const char *what() const _NOEXCEPT;
	};

	void increment();

	void decrement();
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& dt);
#endif
