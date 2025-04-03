/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:51:07 by qliso             #+#    #+#             */
/*   Updated: 2025/04/03 09:35:14 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Static variables
int const	SCForm::_requiredGradeToSign = 145;
int const	SCForm::_requiredGradeToExec = 137;

// Canonical & constructors
SCForm::ShrubberyCreationForm(void) : ShrubberyCreationForm("Undefined")
{}

SCForm::ShrubberyCreationForm(std::string const &target) : 
	AForm("ShrubberyCreationForm", SCForm::_requiredGradeToSign, SCForm::_requiredGradeToExec),
	_target(target)
{}

SCForm::ShrubberyCreationForm(SCForm const &c) :
	SCForm(c._target)
{}

SCForm& SCForm::operator=(SCForm const &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

SCForm::~ShrubberyCreationForm(void) {}

// Getters
const std::string&	SCForm::getTarget(void) const { return this->_target; }

// Member functions & methods
void	SCForm::execute(Bureaucrat const & executor) const
{
	this->canBeExecuted(executor);
	this->SCFormAction();
}

void	SCForm::SCFormAction(void) const
{
	std::string		filename(this->_target + "_shrubbery");
	std::ofstream	file(filename);

	if (!file)
		std::cerr << "Error opening file " << filename << std::endl;
	this->printTree(file);
	file.close();
}

std::ostream& SCForm::printTree(std::ostream &o) const
{
	
	o	<<	"       _-_       \n"
		<<	"    /~~   ~~\\    \n"
		<<	" /~~         ~~\\ \n"
	 	<<	"{               }\n"
	 	<<	" \\  _-     -_  / \n"
	 	<<	"   ~  \\ //  ~   \n"
	 	<<	"_- -   | | _- _  \n"
	 	<<	"  _ -  | |   -_  \n"
	 	<<	"      // \\      " 
		<< std::endl;
	return (o);
}
		
