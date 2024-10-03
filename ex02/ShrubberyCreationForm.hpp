/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:36:57 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/03 15:12:58 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <stdexcept>

class ShrubberyCreationForm : public AForm {

	private:

	std::string	_target;

	public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const& copy);
	~ShrubberyCreationForm();

	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& rhs);

	std::string	getTarget() const;

	void	execute(Bureaucrat const& executor) const;
};

std::ostream &	operator<<(std::ostream & op, ShrubberyCreationForm const & b);

#endif