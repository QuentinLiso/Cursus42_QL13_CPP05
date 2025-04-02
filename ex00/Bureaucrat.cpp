/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:05:36 by qliso             #+#    #+#             */
/*   Updated: 2025/04/01 18:56:31 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const int	Bureaucrat::_highestGrade = 1;
const int	Bureaucrat::_lowestGrade = 150;

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string const &msg) :
	_msg(msg)
{}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (this->_msg.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string const &msg) :
	_msg(msg)
{}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (this->_msg.c_str());
}

Bureaucrat::Bureaucrat(void) : Bureaucrat("Undefined", Bureaucrat::_lowestGrade)
{}

Bureaucrat::Bureaucrat(std::string const &name, int grade) :
	_name(name), _grade(grade)
{
	std::cout << "Constructor for " << name << " assigned grade " << grade << std::endl;
	this->checkGradeThrowExcept();
}


Bureaucrat::Bureaucrat(Bureaucrat const &c) :
	_name(c._name), _grade(c._grade)
{
	std::cout << "Copy constructor for " << c._name << " assigned grade " << c._grade << std::endl;
	this->checkGradeThrowExcept();
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	this->checkGradeThrowExcept();
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called for " << this->_name << std::endl;
}

std::string const	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	this->checkGradeThrowExcept();
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	this->checkGradeThrowExcept();
}

void	Bureaucrat::checkGradeThrowExcept(void) const
{
	if (this->_grade > Bureaucrat::_lowestGrade)
		throw (Bureaucrat::GradeTooLowException("Grade too low"));
	else if (this->_grade < _highestGrade)
		throw (Bureaucrat::GradeTooHighException("Grade too high"));
}

std::ostream&	operator<<(std::ostream& o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}