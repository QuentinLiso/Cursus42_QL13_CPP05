/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:51:05 by qliso             #+#    #+#             */
/*   Updated: 2025/04/02 18:33:44 by qliso            ###   ########.fr       */
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

		const std::string& getTarget(void) const;
		void	execute(Bureaucrat const & executor) const override;
		void	SCFormAction(void) const;
		std::ostream& printTree(std::ostream &o) const;
};

typedef	ShrubberyCreationForm SCForm;

#endif