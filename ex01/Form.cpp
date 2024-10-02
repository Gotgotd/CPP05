/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:16:21 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/02 16:28:53 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

/*////////// CONSTRUCTORS / DESTRUCTORS //////////*/

Form::Form(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExec): _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	this->_signed = false;
}

Form::Form(Form const& copy):
	_name(copy.getName()), 
	_gradeToSign(copy.getGradeToSign()),
	_gradeToExec(copy.getGradeToSign()) 
{
	*this=copy;
}

Form::~Form() {}

/*////////// OVERLOAD //////////*/

Form&	Form::operator=(Form const& rhs) {
	if (this != &rhs) {
		_signed = rhs.getSigned();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & op, Form const & b) {

	op << "Is " << b.getName() << " Form signed : ";
	if (b.getSigned() == false)
		op << " no." << std::endl;
	else
		op << " yes." << std::endl;
	op << b.getName() << " Form needed grade to sign it : " << b.getGradeToSign() << std::endl;
	op << b.getName() << " Form needed grade to execute it : " << b.getGradeToExec() << std::endl;
}

/*////////// GETTERS //////////*/

std::string const	Form::getName() const {
	return this->getName();
}

bool	Form::getSigned() const {
	return this->_signed;
}

int const	Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int const	Form::getGradeToExec() const {
	return this->_gradeToExec;
}

/*//////// MEMBER FUNCTIONS /////////*/

void	Form::beSigned(Bureaucrat const& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

/*////////// EXCEPTIONS //////////*/

const char*	Form::GradeTooHighException::what() const throw() {
	return (" grade is too high.");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return (" grade is too low");
}