/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:35:42 by qliso             #+#    #+#             */
/*   Updated: 2025/04/10 11:22:48 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Static variables
int const	RRForm::_requiredGradeToSign = 72;
int const	RRForm::_requiredGradeToExec = 45;

// Canonical & constructors
RRForm::RobotomyRequestForm(void) :
	AForm("RobotomyRequestForm", RRForm::_requiredGradeToSign, RRForm::_requiredGradeToExec),
	_target("Undefined")
{}

RRForm::RobotomyRequestForm(std::string const & target) :
	AForm("RobotomyRequestForm", RRForm::_requiredGradeToSign, RRForm::_requiredGradeToExec),
	_target(target)
{}

RRForm::RobotomyRequestForm(RobotomyRequestForm const &c) : 
	AForm("RobotomyRequestForm", RRForm::_requiredGradeToSign, RRForm::_requiredGradeToExec),
	_target(c._target)
{}

RRForm& RRForm::operator=(RRForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

RRForm::~RobotomyRequestForm(void) {}

// Getters
const std::string& RRForm::getTarget(void) const { return this->_target; }

// Member functions & methods
void	RRForm::execute(Bureaucrat const &executor) const
{
	this->canBeExecuted(executor);
	this->RRFormAction();
}

void	RRForm::RRFormAction(void) const
{
	int	randomNumber = std::rand() % 2;

	std::cout << "*RRForm is making drilling noise*" << std::endl;
	if (randomNumber == 1)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy on " << this->_target << " has failed" << std::endl;
}