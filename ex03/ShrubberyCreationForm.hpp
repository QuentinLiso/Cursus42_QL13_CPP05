/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:51:05 by qliso             #+#    #+#             */
/*   Updated: 2025/04/10 11:40:33 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <string>
# include <iostream>
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		static int const	_requiredGradeToSign;
		static int const	_requiredGradeToExec;
		std::string			_target;

		ShrubberyCreationForm(void);
		
	public:
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &c);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const &rhs);
		virtual ~ShrubberyCreationForm(void);

		virtual const std::string&	getTarget(void) const;
		virtual void				execute(Bureaucrat const & executor) const;
		void						SCFormAction(void) const;
		std::ostream& 				printTree(std::ostream &o) const;
};

typedef	ShrubberyCreationForm SCForm;

#endif