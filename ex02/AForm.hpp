/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:39:23 by qliso             #+#    #+#             */
/*   Updated: 2025/04/10 11:17:19 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
	private:
		static int const	_highestGrade;
		static int const	_lowestGrade;
		std::string	const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExec;

		AForm(void);

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

		class FormNotSignedException : public std::exception
		{
			private:
				std::string const	_msg;
			public:
				FormNotSignedException(std::string const &msg);
				virtual ~FormNotSignedException(void) throw();
				virtual const char* what(void) const throw();
		};
		
		AForm(std::string const &name, int gradeToSign, int gradeToExec);
		AForm(AForm const &c);
		AForm& operator=(AForm const &rhs);
		virtual ~AForm(void);

		std::string const& getName(void) const;
		bool getSigned(void) const;
		int const & getGradeToSign(void) const;
		int const & getGradeToExec(void) const;
		virtual const std::string& getTarget(void) const = 0;

		void	checkGradeThrowExec(int grade) const;
		void	beSigned(Bureaucrat	const &b);
		void	canBeExecuted(Bureaucrat const &b) const;
		virtual void	execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream& o, AForm& rhs);

#endif