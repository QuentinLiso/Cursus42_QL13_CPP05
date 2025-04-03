/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:34:20 by qliso             #+#    #+#             */
/*   Updated: 2025/04/03 14:38:52 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Exceptions
Intern::UnknownFormException::UnknownFormException(std::string msg) : _msg(msg) {}

const char*	Intern::UnknownFormException::what(void) const throw()
{
	return (this->_msg.c_str());
}

// Canonical & constructors
Intern::Intern(void) {}

Intern::Intern(Intern const &c) {}

Intern&	Intern::operator=(Intern const &rhs) { return (*this); }

Intern::~Intern(void) { std::cout << "Intern destructor called" << std::endl; }

// Member functions
AForm*	Intern::makeSCForm(std::string const &target) const { return (new SCForm(target)); }

AForm*	Intern::makeRRForm(std::string const &target) const { return (new RRForm(target)); }

AForm*	Intern::makePPForm(std::string const &target) const { return (new PPForm(target)); }

AForm*	Intern::makeForm(std::string const &formName, std::string const &target) const
{
	AForm*	(Intern::*f[3])(std::string const &t) const = 
	{ 
		&Intern::makeSCForm, 
		&Intern::makeRRForm, 
		&Intern::makePPForm
	};
	std::string	formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " + formNames[i] << std::endl;
			return ((this->*f[i])(target));
		}
	}
	throw(Intern::UnknownFormException("Form" + formName + " does not exist."));
	return (nullptr);
}
