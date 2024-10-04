/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:05:18 by gautier           #+#    #+#             */
/*   Updated: 2024/10/04 15:05:12 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define CYAN "\033[36m"
# define RESET "\033[0m"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {

	Bureaucrat	Lucien("Lucien", 146);
	Bureaucrat	Jose("Jose", 26);
	Bureaucrat	Bernard("Bernard", 73);

	AForm*	shrub = new ShrubberyCreationForm("Lucien");
	AForm*	prez = new PresidentialPardonForm("Jose");
	AForm*	rob = new RobotomyRequestForm("Bernard");
	
	//test pattern for Lucien
	std::cout << CYAN << "\n------- TEST LUCIEN (starting grade : 146) && SHRUBBERY FORM -------\n" << RESET << std::endl;
	try {
		Lucien.executeForm(*shrub);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Lucien.signForm(*shrub);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	Lucien.incrementGrade();
	Lucien.signForm(*shrub);
	Lucien.signForm(*shrub);
	while (Lucien.getGrade() > shrub->getGradeToExec())
		Lucien.incrementGrade();
	std::cout << std::endl << Lucien;
	std::cout << std:: endl << *shrub << std::endl;
	try {
		Lucien.executeForm(*shrub);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	//Same pattern for Jose
	std::cout << CYAN << "\n------- TEST JOSE (starting grade : 26) && PRESIDENTIAL PARDON FORM -------\n" << RESET << std::endl;
	try {
		Jose.executeForm(*prez);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Jose.signForm(*prez);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	Jose.incrementGrade();
	Jose.signForm(*prez);
	Jose.signForm(*prez);
	while (Jose.getGrade() > prez->getGradeToExec())
		Jose.incrementGrade();
	std::cout << std::endl << Jose;
	std::cout << std:: endl << *prez << std::endl;
	try {
		Jose.executeForm(*prez);
	}
	catch(const std::exception& e) {
		std::cerr << Jose.getName() << " couldn't sign the form. " << e.what() << '\n';
	}
	std::cout << std::endl;

	//Same pattern for Bernard
	std::cout << CYAN << "\n------- TEST BERNARD (starting grade : 73) && ROBOTOMY REQUEST FORM -------\n" << RESET << std::endl;
	try {
		Bernard.executeForm(*rob);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Bernard.signForm(*rob);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	Bernard.incrementGrade();
	Bernard.signForm(*rob);
	Bernard.signForm(*rob);
	while (Bernard.getGrade() > rob->getGradeToExec())
		Bernard.incrementGrade();
	std::cout << std::endl << Bernard;
	std::cout << std:: endl << *rob << std::endl;
	try {
		Bernard.executeForm(*rob);
	}
	catch(const std::exception& e) {
		std::cerr <<Bernard.getName() << " couldn't sign the form. " << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << CYAN << "\n------- INTERN TESTS -------\n" << RESET << std::endl;
	
	Intern	randomIntern;
	AForm*	rrf;

	try {
		rrf = randomIntern.makeForm("random form", "Jesus");
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try {
		rrf = randomIntern.makeForm("robotomy request", "Bernard");
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		Bernard.signForm(*rrf);
		std::cout << std::endl;
		Bernard.executeForm(*rrf);
	}
	catch(const std::exception& e) {
		std::cerr << Bernard.getName() << e.what() << '\n';
	}

	delete	rrf;
	delete shrub;
	delete prez;
	delete rob;

	return 0;
}