/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:03:11 by qliso             #+#    #+#             */
/*   Updated: 2025/04/10 11:17:47 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	trycatchBureaucrat_test1(int grade)
{
	try
	{
		Bureaucrat	*b1 = new Bureaucrat("Didier", grade);
		delete b1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	trycatchBureaucrat_test2(int grade, int i)
{
	Bureaucrat	*b1 = new Bureaucrat("Didier", grade);
	try
	{
		while (i--)
			b1->incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *b1 << std::endl;
	delete b1;
}

void	trycatchBureaucrat_test3(int grade, int i)
{
	Bureaucrat	*b1 = new Bureaucrat("Didier", grade);
	try
	{
		while (i--)
			b1->decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *b1 << std::endl;
	delete b1;
}

int	main(void)
{
	std::srand(std::time(NULL));

	trycatchBureaucrat_test1(5);
	trycatchBureaucrat_test1(1);
	trycatchBureaucrat_test1(152);
	trycatchBureaucrat_test1(0);

	trycatchBureaucrat_test2(5, 10);
	trycatchBureaucrat_test3(140, 18);

	Bureaucrat	*b1 = new Bureaucrat("Didier", 42);
	SCForm		*f1 = new SCForm("Jean-Pierre");
	RRForm		*f2 = new RRForm("Fredo");
	PPForm		*f3 = new PPForm("Luc");

	b1->executeForm(*f1);
	b1->signForm(*f1);
	b1->executeForm(*f1);

	b1->executeForm(*f2);
	b1->signForm(*f2);
	b1->executeForm(*f2);

	b1->executeForm(*f3);
	b1->signForm(*f3);
	b1->executeForm(*f3);

	delete b1;
	delete f1;
	delete f2;
	delete f3;

	return (0);
}