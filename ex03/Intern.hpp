/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:34:18 by qliso             #+#    #+#             */
/*   Updated: 2025/04/10 11:44:25 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>
# include <iostream>

class	Intern
{
	private:
		AForm*	makeSCForm(std::string const &target) const;
		AForm*	makeRRForm(std::string const &target) const;
		AForm*	makePPForm(std::string const &target) const;

	public:
		class UnknownFormException : public std::exception
		{
			private:
				std::string	_msg;
			public:
				UnknownFormException(std::string msg);
				virtual ~UnknownFormException(void) throw();
				virtual const char* what() const throw();
		};

		Intern(void);
		Intern(Intern const &c);
		Intern& operator=(Intern const &rhs);
		virtual ~Intern(void);

		AForm*	makeForm(std::string const &formName, std::string const &target) const;
};

#endif