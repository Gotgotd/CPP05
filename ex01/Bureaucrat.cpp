/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:21:50 by gautier           #+#    #+#             */
/*   Updated: 2024/10/10 15:34:46 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


/*////////// CONSTRUCTORS / DESTRUCTORS //////////*/

Bureaucrat::Bureaucrat() {};

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	
	try {
		_grade = grade;
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (std::exception & e){
		std::cout << "constructor of this class with '" << _name << "' " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) {
	*this=copy;
}

Bureaucrat::~Bureaucrat() {}

/*////////// OVERLOAD //////////*/

Bureaucrat& 	Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs) {
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream&	operator<<(std::ostream & op, Bureaucrat const & b) {
	op << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return op;
}

/*////////// GETTERS - SETTERS //////////*/

std::string const &	Bureaucrat::getName() const {
	return this->_name;
}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

void	Bureaucrat::setGrade(int grade) {
	this->_grade = grade;
}

/*//////// MEMBER FUNCTIONS /////////*/

void	Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrementGrade() {
	
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void	Bureaucrat::signForm(Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because" << e.what() << std::endl;
	}

}

/*////////// EXCEPTIONS //////////*/

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("'s grade is too high.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("'s grade is too low");
}
