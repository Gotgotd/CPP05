/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:26:51 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/04 14:40:01 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <stdexcept>

class RobotomyRequestForm : public AForm {

	private:

	std::string	_target;

	public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const& copy);
	~RobotomyRequestForm();

	RobotomyRequestForm&	operator=(RobotomyRequestForm const& rhs);

	std::string	getTarget() const;

	void	execute(Bureaucrat const& executor) const;
	static AForm*	createForm(std::string target);
};

std::ostream &	operator<<(std::ostream & op, RobotomyRequestForm const & b);

#endif