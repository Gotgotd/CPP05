/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:21:50 by gautier           #+#    #+#             */
/*   Updated: 2024/09/27 15:44:58 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {};

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {

	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) {
	*this=copy;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& 	Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs) {
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::string const &	Bureaucrat::getName() const {
	return this->_name;
}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

void	Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
}

void	Bureaucrat::decrementGrade() {
	
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("'s grade is too high.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("'s grade is too low");
}

std::ostream&	operator<<(std::ostream & op, Bureaucrat const & b) {
	op << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return op;
}