/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:39:23 by qliso             #+#    #+#             */
/*   Updated: 2025/04/10 11:05:45 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
	private:
		static int const	_highestGrade;
		static int const	_lowestGrade;
		std::string	const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExec;

		Form(void);

	public:
		class GradeTooHighException : public std::exception
		{
			private:
				std::string const	_msg;
			public:
				GradeTooHighException(std::string const &msg);
				virtual ~GradeTooHighException(void) throw();
				virtual	const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				std::string const	_msg;
			public:
				GradeTooLowException(std::string const &msg);
				virtual ~GradeTooLowException(void) throw();
				virtual const char* what(void) const throw();
		};
		
		Form(std::string const &name, int gradeToSign, int gradeToExec);
		Form(Form const &c);
		Form& operator=(Form const &rhs);
		virtual ~Form(void);

		std::string const& getName(void) const;
		bool getSigned(void) const;
		int const & getGradeToSign(void) const;
		int const & getGradeToExec(void) const;

		void	checkGradeThrowExec(int grade) const;
		void	beSigned(Bureaucrat	const &b);
};

std::ostream& operator<<(std::ostream& o, Form& rhs);

#endif