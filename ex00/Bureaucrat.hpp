/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:05:32 by gautier           #+#    #+#             */
/*   Updated: 2024/09/27 15:26:02 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

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

	void	incrementGrade();
	void	decrementGrade();

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