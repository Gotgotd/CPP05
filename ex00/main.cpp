/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:05:18 by gautier           #+#    #+#             */
/*   Updated: 2024/10/10 15:30:53 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {

	Bureaucrat	Lucien("lucien", -1);
	Bureaucrat	Jose("Jose", 156);

	Lucien.setGrade(1);
	Jose.setGrade(150);
	
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

	return 0;
}