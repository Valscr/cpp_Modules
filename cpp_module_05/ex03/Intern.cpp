/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:47:12 by valentin          #+#    #+#             */
/*   Updated: 2023/06/05 15:26:18 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& src)
{
    *this = src;
}

Intern& Intern::operator=(const Intern& src)
{
    (void)src;
    return (*this);
}

Form *callShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

Form *callRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

Form *callPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(std::string name_form, std::string target)
{
    typedef Form *(*funcPtr)(std::string target);
    std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    funcPtr Form[3] = {&callRobotomyRequestForm, &callPresidentialPardonForm, &callShrubberyCreationForm};
    
    for (int i(0); i < 3; i++) {
        if (name_form == formNames[i]) {
            std::cout << "Intern creates " << name_form << std::endl;
            return (Form[i](target));
        }
    }
    std::cout << "Intern cannot create " << name_form << " form" << std::endl;
    return NULL;
}