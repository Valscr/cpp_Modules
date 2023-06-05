/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:38:49 by valentin          #+#    #+#             */
/*   Updated: 2023/06/05 14:06:38 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
    this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void        RobotomyRequestForm::execute(const Bureaucrat& src) const
{
    if (this->getSigned() == false)
        throw Form::NotSignedException();
    else if (src.getGrade() > this->getGradeExec())
        throw Bureaucrat::GradeTooLowException();
    std::cout << src.getName() << " executed " << _target << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << _target << " has been robotomized!" << std::endl;
    else
        std::cout << "Robotomy of " << _target << " failed!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : Form( src ), _target( src._target ) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& src)
{
    (void)src;
    return *this;
}