/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:03:11 by qliso             #+#    #+#             */
/*   Updated: 2025/04/03 14:46:15 by qliso            ###   ########.fr       */
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
#include "Intern.hpp"

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

void	trycatchIntern_test4(int grade, std::string formName)
{
	Intern	someRandomIntern;
	Bureaucrat	*b1 = new Bureaucrat("Didier", grade);
	AForm*	f1;

	try
	{
		f1 = someRandomIntern.makeForm(formName, "Bender");
		try
		{
			b1->signForm(*f1);
			b1->executeForm(*f1);
		}
		catch (std::exception const &e)
		{
			std::cerr << e.what() << std::endl;
		}		
		delete f1;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete b1;
}

int	main(void)
{
	std::srand(std::time(nullptr));

	trycatchBureaucrat_test1(5);
	trycatchBureaucrat_test1(1);
	trycatchBureaucrat_test1(152);
	trycatchBureaucrat_test1(0);

	trycatchBureaucrat_test2(5, 10);
	trycatchBureaucrat_test3(140, 18);

	trycatchIntern_test4(4, "shrubbery creation");
	trycatchIntern_test4(4, "robotomy request");
	trycatchIntern_test4(4, "presidential pardon");
	trycatchIntern_test4(4, "zabebi");
	trycatchIntern_test4(123, "robotomy request");

	return (0);
}