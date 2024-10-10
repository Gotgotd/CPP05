/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:05:32 by gautier           #+#    #+#             */
/*   Updated: 2024/10/10 15:30:53 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Form.hpp"

class	Form;

class	Bureaucrat {

	private:

	std::string	const	_name;
	int					_grade;

	public:

	Bureaucrat();
	Bureaucrat(Bureaucrat const & copy);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	Bureaucrat&			operator=(Bureaucrat const & rhs);
	std::string const&	getName() const;
	int					getGrade() const;
	void				setGrade(int grade);

	void	incrementGrade();
	void	decrementGrade();
	void	signForm(Form& form) const;

	class GradeTooHighException : public std::exception {

		public:
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
		virtual const char* what() const throw();
	};
};

std::ostream &	operator<<(std::ostream & op, Bureaucrat const & b);

#endif