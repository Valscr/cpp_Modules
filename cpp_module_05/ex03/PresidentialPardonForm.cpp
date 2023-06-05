/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:09:00 by valentin          #+#    #+#             */
/*   Updated: 2023/06/05 14:07:14 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5)
{
    this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void        PresidentialPardonForm::execute(const Bureaucrat& src) const
{
    if (this->getSigned() == false)
        throw Form::NotSignedException();
    else if (src.getGrade() > this->getGradeExec())
        throw Bureaucrat::GradeTooLowException();
    std::cout << src.getName() << " executed " << _target << std::endl;
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : Form( src ), _target( src._target ) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& src)
{
    (void)src;
    return *this;
}