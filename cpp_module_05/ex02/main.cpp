/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:23:12 by valentin          #+#    #+#             */
/*   Updated: 2023/06/05 14:07:39 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat bureau1("bureau1", 5);
        ShrubberyCreationForm shruberry("file");
        shruberry.beSigned(bureau1);
        bureau1.signform(shruberry);
        bureau1.executeForm(shruberry);

        std::cout << std::endl;

        RobotomyRequestForm robot("Robot");
        robot.beSigned(bureau1);
        bureau1.signform(robot);
        bureau1.executeForm(robot);

        std::cout << std::endl;

        PresidentialPardonForm president("President");
        president.beSigned(bureau1);
        bureau1.signform(president);
        bureau1.executeForm(president);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}