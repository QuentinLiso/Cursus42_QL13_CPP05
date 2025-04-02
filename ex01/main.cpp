/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:03:11 by qliso             #+#    #+#             */
/*   Updated: 2025/04/02 14:11:53 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "****************** TEST : **********************" << std::endl << std::endl;
	Form	f1("Cerfa 12934", 10, 5);
	Bureaucrat	b1("Didier",  11);

	std::cout << f1;
	
	b1.signForm(f1);
	std::cout << f1;
	b1.incrementGrade();
	b1.decrementGrade();
	b1.incrementGrade();
	b1.signForm(f1);
	std::cout << f1;

	std::cout << "****************** TEST : **********************" << std::endl << std::endl;
	try
	{
		Form	f2("Cerfa 122-AB3.2", 151, 20);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Form	f3("Cerfa 122-AB3.3", 20, 151);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Form	f4("Cerfa 122-AB3.4", 151, 151);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Form	f5("Cerfa 122-AB3.5", -1, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}