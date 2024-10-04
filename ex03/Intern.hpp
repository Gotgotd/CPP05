/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:28:15 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/04 14:40:01 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {

	public: 

	Intern();
	Intern(Intern const& copy);
	~Intern();

	Intern&	operator=(Intern const& rhs);

	AForm*	makeForm(std::string formName, std::string formTarget);

	class WrongFormNameException : public std::exception {
		public:
		virtual const char* what() const throw();
	};
};

#endif