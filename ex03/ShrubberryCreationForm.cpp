/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberryCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:32:17 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/04 14:40:01 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

 std::string tree = 
		"        /\\\n"
		"       /**\\\n"
		"      /****\\\n"
		"     /******\\\n"
		"    /********\\\n"
		"   /**********\\\n"
		"  /************\\\n"
		" /**************\\\n"
		"/****************\\\n"
		"       ||||\n"
		"       ||||\n";

/*////////// CONSTRUCTORS / DESTRUCTORS //////////*/

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberryCreationForm", 145, 137), _target(NULL) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & copy ) {
	*this=copy;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberryCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/*////////// OVERLOAD //////////*/

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs) {

	if (this != &rhs) {
		_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & op, ShrubberyCreationForm const & b) {

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

std::string	ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

/*//////// MEMBER FUNCTIONS /////////*/

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const {

	if (getSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > getGradeToExec()) {
		throw GradeTooLowException();
	}
	else {
		std::ofstream	file((this->getTarget() + "_shrubbery").c_str());
		if (!file.is_open()) 
			std::cerr << "Error. File " << getTarget() << "_shrubbery could not be opened" << std::endl;
		file << tree;
		file.close();
	}
}

AForm*	ShrubberyCreationForm::createForm(std::string target) {
	return new ShrubberyCreationForm(target);
}