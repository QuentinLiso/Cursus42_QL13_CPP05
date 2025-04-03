/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:10:53 by qliso             #+#    #+#             */
/*   Updated: 2025/04/03 09:14:37 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <string>
# include <iostream>

class	PresidentialPardonForm : public AForm
{
	private:
		static int const	_requiredGradeToSign;
		static int const	_requiredGradeToExec;
		std::string 		_target;
	
		PresidentialPardonForm(void);

	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &c);
		PresidentialPardonForm& operator=(PresidentialPardonForm const &rhs);
		virtual ~PresidentialPardonForm(void);

		const std::string& getTarget(void) const;
		void	execute(Bureaucrat const & executor) const override;
		void	PPFormAction(void) const;
};

typedef PresidentialPardonForm PPForm;

#endif