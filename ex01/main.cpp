/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:05:18 by gautier           #+#    #+#             */
/*   Updated: 2024/10/04 15:13:32 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {

	Bureaucrat	Lucien("Lucien", 1);
	Bureaucrat	Jose("Jose", 150);

	try {
		Lucien.incrementGrade();
	}
	catch(const std::exception& e) {
		
		std::cerr << Lucien.getName() << e.what() << '\n';
	}
	try {
		Jose.decrementGrade();
	}
	catch(const std::exception& e) {
		std::cerr << Jose.getName() << e.what() << '\n';
	}
	
	try {
		std::cout << Lucien;
		Lucien.decrementGrade();
		std::cout << Lucien;
		std::cout << Jose;
		Jose.incrementGrade();
		std::cout << Jose;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	Form	contract("contract", 75, 50);

	Jose.signForm(contract);
	Lucien.signForm(contract);

	return 0;
}