/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:05:34 by qliso             #+#    #+#             */
/*   Updated: 2025/04/10 11:04:01 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include <iostream>
# include <string>
# include <exception>

class	Form;

class	Bureaucrat
{
	private:
		static const int	_highestGrade;
		static const int	_lowestGrade;
		std::string	const	_name;
		int					_grade;

		Bureaucrat(void);

	public:
		class GradeTooHighException : public std::exception
		{
			private:
				std::string	_msg;
				
			public:
				GradeTooHighException(std::string const &msg);
				virtual ~GradeTooHighException(void) throw();
				virtual const char*	what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			private:
				std::string	_msg;
				
			public:
				GradeTooLowException(std::string const &msg);
				virtual ~GradeTooLowException(void) throw();
				virtual const char*	what(void) const throw();
		};

		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &c);
		Bureaucrat&	operator=(Bureaucrat const &rhs);
		virtual ~Bureaucrat(void);

		std::string const	getName(void) const;
		int		getGrade(void) const;
		void	incrementGrade(void);
		void	decrementGrade(void);
		void 	checkGradeThrowExcept(int grade) const;
		void	signForm(Form &f) const;
};

std::ostream&	operator<<(std::ostream& o, Bureaucrat const &rhs);

#endif