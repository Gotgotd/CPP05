/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:44:46 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/03 15:48:51 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <stdexcept>

class PresidentialPardonForm : public AForm {

	private:

	std::string	_target;

	public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const& copy);
	~PresidentialPardonForm();

	PresidentialPardonForm&	operator=(PresidentialPardonForm const& rhs);

	std::string	getTarget() const;

	void	execute(Bureaucrat const& executor) const;
};

std::ostream &	operator<<(std::ostream & op, PresidentialPardonForm const & b);

#endif