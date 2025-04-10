/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:10:51 by qliso             #+#    #+#             */
/*   Updated: 2025/04/10 11:23:11 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Static variables
int const	PPForm::_requiredGradeToSign = 25;
int const	PPForm::_requiredGradeToExec = 5;

// Canonical & constructors
PPForm::PresidentialPardonForm(void) : 
	AForm("PresidentialPardonForm", PPForm::_requiredGradeToSign, PPForm::_requiredGradeToExec),
	_target("Undefined")
{}

PPForm::PresidentialPardonForm(std::string const &target) : 
	AForm("PresidentialPardonForm", PPForm::_requiredGradeToSign, PPForm::_requiredGradeToExec),
	_target(target)
{}

PPForm::PresidentialPardonForm(PPForm const &c) : 
	AForm("PresidentialPardonForm", PPForm::_requiredGradeToSign, PPForm::_requiredGradeToExec),
	_target(c._target)
{}

PPForm& PPForm::operator=(PPForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

PPForm::~PresidentialPardonForm(void) {}

// Getters
const std::string& PPForm::getTarget(void) const { return this->_target; }

// Member functions & methods
void	PPForm::execute(Bureaucrat const & executor) const
{
	this->canBeExecuted(executor);
	this->PPFormAction();
}

void	PPForm::PPFormAction(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

