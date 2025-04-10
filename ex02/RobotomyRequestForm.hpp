/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:35:40 by qliso             #+#    #+#             */
/*   Updated: 2025/04/10 11:16:53 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <string>
# include <iostream>
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		static int const	_requiredGradeToSign;
		static int const	_requiredGradeToExec;
		std::string			_target;

		RobotomyRequestForm(void);

	public:
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const &c);
		RobotomyRequestForm& operator=(RobotomyRequestForm const &rhs);
		virtual ~RobotomyRequestForm(void);

		const std::string&	getTarget(void) const;
		virtual void		execute(Bureaucrat const & executor) const;
		void				RRFormAction(void) const;
};

typedef RobotomyRequestForm RRForm;

#endif