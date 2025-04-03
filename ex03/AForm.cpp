/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:39:25 by qliso             #+#    #+#             */
/*   Updated: 2025/04/03 10:29:10 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Static const variables
int const	AForm::_highestGrade = 1;
int const	AForm::_lowestGrade = 150;


// Exceptions
AForm::GradeTooHighException::GradeTooHighException(std::string const &msg) : _msg(msg) {}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return (this->_msg.c_str());
}

AForm::GradeTooLowException::GradeTooLowException(std::string const &msg) : _msg(msg) {}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return (this->_msg.c_str());
}

AForm::FormNotSignedException::FormNotSignedException(std::string const &msg) : _msg(msg) {}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return (this->_msg.c_str());
}

// Canonical & constructors
AForm::AForm(void) : AForm("Undefined", 1, 1) {}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExec) :
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	checkGradeThrowExec(gradeToSign);
	checkGradeThrowExec(gradeToExec);
}

AForm::AForm(AForm const &c) :
	_name(c._name), _signed(c._signed), _gradeToSign(c._gradeToSign), _gradeToExec(c._gradeToExec)
{
	checkGradeThrowExec(c._gradeToSign);
	checkGradeThrowExec(c._gradeToExec);
}

AForm&	AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	checkGradeThrowExec(this->_gradeToSign);
	checkGradeThrowExec(this->_gradeToExec);
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "Destructor called for " << this->_name << std::endl;
}

// Getters
std::string const&	AForm::getName(void) const { return (this->_name); }

bool	AForm::getSigned(void) const { return (this->_signed); }

int const & AForm::getGradeToSign(void) const { return (this->_gradeToSign); }

int const & AForm::getGradeToExec(void) const { return (this->_gradeToExec); }

// Member functions
void	AForm::checkGradeThrowExec(int grade) const
{
	if (grade < AForm::_highestGrade)
		throw(AForm::GradeTooHighException("Grade Too High !"));
	if (grade > AForm::_lowestGrade)
		throw(AForm::GradeTooLowException("Grade Too Low !"));
}

void	AForm::beSigned(Bureaucrat const &b)
{
	if (this->_gradeToSign < b.getGrade())
		throw(AForm::GradeTooLowException(b.getName() + "'s grade is too low to sign "  + this->_name));
	this->_signed = true;
}

void	AForm::canBeExecuted(Bureaucrat const &b) const
{
	if (!this->_signed)
		throw(AForm::FormNotSignedException(this->_name + " is not signed and cannot be executed!"));
	if (this->_gradeToExec < b.getGrade())
		throw(AForm::GradeTooLowException(b.getName() + "'s grade is too low to execute " + this->_name));
}

// Non-member functions
std::ostream&	operator<<(std::ostream &o, AForm& rhs)
{
	o << "Form " + rhs.getName() << "; ";
	o << "Signed : " << (rhs.getSigned() ? "yes" : "no") << "; ";
	o << "Grade to sign : " << rhs.getGradeToSign() << "; ";
	o << "Grade to exec : " << rhs.getGradeToExec() << std::endl;
	return (o);
}
