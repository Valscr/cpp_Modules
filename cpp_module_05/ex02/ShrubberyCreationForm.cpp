/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:32:25 by valentin          #+#    #+#             */
/*   Updated: 2023/06/05 14:07:00 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
    this->_target = target + "_shrubbery";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& src)
{
    (void)src;
    return *this;
}

void        ShrubberyCreationForm::execute(const Bureaucrat& src) const
{
    if (this->getSigned() == false)
        throw Form::NotSignedException();
    else if (src.getGrade() > this->getGradeExec())
        throw Bureaucrat::GradeTooLowException();
    std::cout << src.getName() << " executed " << _target << std::endl;
    std::cout << "Creating " << this->_target << " file" << std::endl;
    std::ofstream   ofs(this->_target);
    ofs << "          &&& &&  & &&" << std::endl;
    ofs << "      && &/&|& ()|/ @, &&" << std::endl;
    ofs << "      &/(/&/&||/& /_/)_&/_&" << std::endl;
    ofs << "   &() &/&|()|/|/ '%` & ()" << std::endl;
    ofs << "  &_|_&&_| |& |&&/&__%_/_& &&" << std::endl;
    ofs << "&&   && & &| &| /& & % ()& /&&" << std::endl;
    ofs << " ()&_---()&|&||&&-&&--%---()~" << std::endl;
    ofs << "     &&     ||||" << std::endl;
    ofs << "             |||" << std::endl;
    ofs << "             |||" << std::endl;
    ofs << "             |||" << std::endl;
    ofs << "       , -=-~  .-^- _" << std::endl;
    ofs.close();
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) : Form( src ), _target( src._target ) {}