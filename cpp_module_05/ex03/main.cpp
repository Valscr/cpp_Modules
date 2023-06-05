/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:23:12 by valentin          #+#    #+#             */
/*   Updated: 2023/06/05 15:37:52 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern Intern;

    Form* form1 = Intern.makeForm("shrubbery creation", "form1");
    Form* form2 = Intern.makeForm("robotomy request", "form2");
    Form* form3 = Intern.makeForm("presidential pardon", "form3");
    std::cout << *form1;
    std::cout << *form2;
    std::cout << *form3;
    delete form1;
    delete form2;
    delete form3;
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