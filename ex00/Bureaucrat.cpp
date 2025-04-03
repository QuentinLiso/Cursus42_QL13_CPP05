/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:05:36 by qliso             #+#    #+#             */
/*   Updated: 2025/04/03 10:19:16 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Static variables
const int	Bureaucrat::_highestGrade = 1;
const int	Bureaucrat::_lowestGrade = 150;

// Exceptions
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

// Canonical & constructors
Bureaucrat::Bureaucrat(void) : Bureaucrat("Undefined", Bureaucrat::_lowestGrade) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade) :
	_name(name), _grade(grade)
{
	std::cout << "Constructor for " << name << " assigned grade " << grade << std::endl;
	this->checkGradeThrowExcept(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &c) :
	_name(c._name), _grade(c._grade)
{
	std::cout << "Copy constructor for " << c._name << " assigned grade " << c._grade << std::endl;
	this->checkGradeThrowExcept(c._grade);
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	this->checkGradeThrowExcept(this->_grade);
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called for " << this->_name << std::endl;
}

// Getters
std::string const	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

// Member functions
void	Bureaucrat::incrementGrade(void)
{
	int	newGrade = this->_grade;
	
	newGrade--;
	checkGradeThrowExcept(newGrade);
	this->_grade = newGrade;
	std::cout << this->_name << " was promoted to grade " << this->_grade << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	int	newGrade = this->_grade;
	
	newGrade++;
	checkGradeThrowExcept(newGrade);
	this->_grade = newGrade;
	std::cout << this->_name << " was downgraded to grade " << this->_grade << std::endl;
}

void	Bureaucrat::checkGradeThrowExcept(int grade) const
{
	if (grade < Bureaucrat::_highestGrade)
		throw (Bureaucrat::GradeTooHighException("Grade too high"));
	else if (grade > Bureaucrat::_lowestGrade)
		throw (Bureaucrat::GradeTooLowException("Grade too low"));
}

// Non-member functions
std::ostream&	operator<<(std::ostream& o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}