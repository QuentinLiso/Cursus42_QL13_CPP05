/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:39:25 by qliso             #+#    #+#             */
/*   Updated: 2025/04/02 14:14:53 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Static const variables
int const	Form::_highestGrade = 1;
int const	Form::_lowestGrade = 150;


// Exceptions
Form::GradeTooHighException::GradeTooHighException(std::string const &msg) : _msg(msg) {}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return (this->_msg.c_str());
}

Form::GradeTooLowException::GradeTooLowException(std::string const &msg) : _msg(msg) {}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return (this->_msg.c_str());
}


// Canonical & constructors
Form::Form(void) : Form("Undefined", 1, 1) {}

Form::Form(std::string const &name, int gradeToSign, int gradeToExec) :
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	checkGradeThrowExec();
}

Form::Form(Form const &c) :
	_name(c._name), _gradeToSign(c._gradeToSign), _gradeToExec(c._gradeToExec)
{
	checkGradeThrowExec();
}

Form&	Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	checkGradeThrowExec();
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Destructor called for " << this->_name << std::endl;
}

// Getters
std::string const&	Form::getName(void) const { return (this->_name); }

bool	Form::getSigned(void) const { return (this->_signed); }

int const & Form::getGradeToSign(void) const { return (this->_gradeToSign); }

int const & Form::getGradeToExec(void) const { return (this->_gradeToExec); }

// Member functions
void	Form::checkGradeThrowExec(void) const
{
	if (this->_gradeToSign < Form::_highestGrade || this->_gradeToExec < Form::_highestGrade)
		throw(Form::GradeTooHighException("Grade Too High !"));
	if (this->_gradeToSign > Form::_lowestGrade || this->_gradeToExec > Form::_lowestGrade)
		throw(Form::GradeTooLowException("Grade Too Low !"));
}

void	Form::beSigned(Bureaucrat const &b)
{
	if (this->_gradeToSign < b.getGrade())
		throw(Form::GradeTooLowException("the grade is too low to sign!"));
	this->_signed = true;
}

// Non-member functions
std::ostream&	operator<<(std::ostream &o, Form& rhs)
{
	o << "Form " + rhs.getName() << "; ";
	o << "Signed : " << (rhs.getSigned() ? "yes" : "no") << "; ";
	o << "Grade to sign : " << rhs.getGradeToSign() << "; ";
	o << "Grade to exec : " << rhs.getGradeToExec() << std::endl;
	return (o);
}
