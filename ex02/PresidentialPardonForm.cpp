/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:43:17 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/03 18:00:00 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

/*////////// CONSTRUCTORS / DESTRUCTORS //////////*/

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target(NULL) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & copy ) {
	*this=copy;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

/*////////// OVERLOAD //////////*/

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs) {

	if (this != &rhs) {
		_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & op, PresidentialPardonForm const & b) {

	op << "Is " << b.getName() << " Form signed : ";
	if (b.getSigned() == false)
		op << " no." << std::endl;
	else
		op << " yes." << std::endl;
	op << b.getName() << " Form needed grade to sign it : " << b.getGradeToSign() << std::endl;
	op << b.getName() << " Form needed grade to execute it : " << b.getGradeToExec() << std::endl;
	op << "this " << b.getName() <<  "Form is for " << b.getTarget() << std::endl;
	
	return op;
}


/*////////// GETTERS //////////*/

std::string	PresidentialPardonForm::getTarget() const {
	return this->_target;
}

/*//////// MEMBER FUNCTIONS /////////*/

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {

	if (getSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() < getGradeToExec()) {
		throw GradeTooLowException();
	}
	else {
		std::cout << "Dear " << _target << ", you have been pardonned by president Zaphod Beeblebrox. ALL HAIL GLORIOUS ZAPHOD !" << std::endl;
	}
}