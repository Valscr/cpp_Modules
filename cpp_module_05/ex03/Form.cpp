/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 23:08:36 by valentin          #+#    #+#             */
/*   Updated: 2023/06/05 14:04:40 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

std::string Form:: getName(void) const
{
    return (this->name);
}

unsigned int Form:: getGradeSigne(void) const
{
    return (this->grade_signe);
}

unsigned int Form:: getGradeExec(void) const
{
    return (this->grade_exec);
}

bool Form:: getSigned(void) const
{
    return (this->signe);
}

Form::Form(Form const &src) : name( src.getName() ), grade_signe( src.getGradeSigne() ), grade_exec( src.getGradeExec() )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Form& Form::operator=(const Form &src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
        signe = src.getSigned();
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Form const &src)
{
    o << src.getName() << " grade signe :" << src.getGradeSigne() << "  grade exec :" << src.getGradeExec() << std::endl;
    return (o);
}

Form::Form(std::string name, unsigned int const grade_signe, unsigned int const grade_exec) :  name(name), grade_signe(grade_signe), grade_exec(grade_exec)
{ 
    this->signe = false;
        if (grade_signe > 150 || grade_exec > 150)
            throw Form::GradeTooLowException();
        else if (grade_signe < 1 || grade_exec < 1)
            throw Form::GradeTooHighException();
}

void    Form::beSigned(Bureaucrat const &src)
{
    try {
        if (src.getGrade() > grade_signe)
            throw Bureaucrat::GradeTooLowException();
        else
            this->signe = true;
        }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << src.getName() << " coulnd't sign " << this->name << " because " << e.what() << std::endl;
    }
}

Form::~Form()
{
}