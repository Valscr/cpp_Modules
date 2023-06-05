/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:22:43 by valentin          #+#    #+#             */
/*   Updated: 2023/06/05 13:53:46 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::string Bureaucrat:: getName(void) const
{
    return (this->name);
}

unsigned int Bureaucrat:: getGrade(void) const
{
    return (this->grade);
}

void    Bureaucrat::incrementGrade(unsigned int)
{
    this->grade -= 1;
}

void    Bureaucrat::decrementGrade(unsigned int)
{
    this->grade += 1;
}

void    Bureaucrat::signform(Form &form)
{
    if (form.getSigned() == true)
    {
        form.beSigned( *this );
        std::cout << this->name << " has signed " << form.getName() << std::endl;
    }
    else
        std::cout << this->name << " has not signed " << form.getName() << std::endl;    
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
        grade = src.getGrade();
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src)
{
    o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return (o);
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) :  name(name), grade(grade)
{  
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

void    Bureaucrat::executeForm(const Form& form) const
{
    form.execute(*this);
}
