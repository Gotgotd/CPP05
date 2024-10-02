/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:46:53 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/02 15:42:16 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Form {

	private:

	std::string const	_name;
	bool				_signed;
	int const			_gradeToSign;
	int const			_gradeToExec;

	public:

	Form();
	Form(std::string name, int gradeToSign, int gradeToExec);
	Form(Form const& copy);
	~Form();

	Form&	operator=(Form const& rhs);

	std::string const	getName() const;
	bool				getSigned() const;
	int const			getGradeToSign() const;
	int const			getGradeToExec() const;

	void	beSigned(Bureaucrat const& bureaucrat);

	class GradeTooHighException : public std::exception {

	public:
	virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
		virtual const char* what() const throw();
	};
};

std::ostream &	operator<<(std::ostream & op, Form const & b);

#endif