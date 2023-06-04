/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:59:11 by valentin          #+#    #+#             */
/*   Updated: 2023/06/04 22:17:01 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const name;
        bool signe;
        unsigned int const grade_signe; 
        unsigned int const grade_exec;
        Form();
    public:
        ~Form();
        Form(std::string name, unsigned int const grade_signe, unsigned int const grade_exec);
        Form(const Form &src);
        Form& operator=(const Form &src);
        std::string getName(void) const;
        void beSigned(Bureaucrat const &src);
        bool getSigned(void) const;
        unsigned int getGradeSigne(void) const;
        unsigned int getGradeExec(void) const;
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade form too high"; }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade form too low"; }
        };
};
std::ostream &operator<<(std::ostream &o, Form const &src);

#endif