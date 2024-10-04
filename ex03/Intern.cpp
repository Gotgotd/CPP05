/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:38:26 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/04 14:43:33 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const& copy) {
	*this=copy;
}

Intern::~Intern() {}

Intern&	Intern::operator=(Intern const& rhs) {
	(void)rhs;
	return *this;	
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget) {

	std::string	names[3] = {"presidential pardon", "shrubbery creation", "robotomy request"};
	AForm* (*formCreator[3])(std::string Target) = {PresidentialPardonForm::createForm, ShrubberyCreationForm::createForm, RobotomyRequestForm::createForm}; 
	for (int i = 0; i < 4; i++) {
		if (names[i] == formName) {
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return formCreator[i](formTarget);
		}
	}
	throw WrongFormNameException();
}

const char*	Intern::WrongFormNameException::what() const throw() {
	return "this form doesn't exist. Please chose among those ones : presidential pardon, shrubbery creation, robotomy request";
}