/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:03:11 by qliso             #+#    #+#             */
/*   Updated: 2025/04/01 17:54:17 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"


int	main(void)
{
	Bureaucrat	*b1;
	Bureaucrat	*b2;
	Bureaucrat	*b3;

	std::cout << "****************** TEST : **********************" << std::endl << std::endl;
	try
	{
		b1 = new Bureaucrat("Quentin", 255);
		std::cout << *b1 << std::endl;
		delete b1;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "****************** TEST : **********************" << std::endl << std::endl;
	try
	{
		b2 = new Bureaucrat("Zizou", 10);
		std::cout << *b2 << std::endl;
		delete b2;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "****************** TEST : **********************" << std::endl << std::endl;
	try
	{
		b3 = new Bureaucrat("Sammy Traoré", -1);
		std::cout << *b3 << std::endl;
		delete b3;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "****************** TEST : **********************" << std::endl << std::endl;
	try
	{
		Bureaucrat b4 = Bureaucrat("Zlatan", 3);
		std::cout << b4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "****************** TEST : **********************" << std::endl << std::endl;
	try
	{
		Bureaucrat	*b5 = new Bureaucrat("Ousmane Dembele", 11);
		Bureaucrat b6 (*b5);
		std::cout << *b5 << std::endl;
		std::cout << b6 << std::endl;
		delete b5;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "****************** TEST : **********************" << std::endl << std::endl;
	try
	{
		Bureaucrat	*b7 = new Bureaucrat("Chief", 3);
		std::cout << *b7 << std::endl;
		try
		{
			b7->incrementGrade();
			b7->incrementGrade();
			std::cout << *b7 << std::endl;
			b7->incrementGrade();
			std::cout << *b7 << std::endl;
			b7->incrementGrade();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete b7;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "****************** TEST : **********************" << std::endl << std::endl;
	try
	{
		Bureaucrat	*b8 = new Bureaucrat("Larbing", 147);
		std::cout << *b8 << std::endl;
		try
		{
			b8->decrementGrade();
			b8->decrementGrade();
			std::cout << *b8 << std::endl;
			b8->decrementGrade();
			std::cout << *b8 << std::endl;
			b8->decrementGrade();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete b8;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}