/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:23:01 by valentin          #+#    #+#             */
/*   Updated: 2023/06/05 13:35:01 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const name;
        unsigned int grade;
        Bureaucrat();
    public:
        
        Bureaucrat(std::string name, unsigned int grade);
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &src);
        Bureaucrat& operator=(const Bureaucrat &src);
        std::string getName(void) const;
        void    executeForm(const Form& form) const;
        void    signform(Form &form);
        unsigned int getGrade(void) const;
        void    incrementGrade(unsigned int);
        void    decrementGrade(unsigned int);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade of Bureaucrat too high"; }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade of Bureaucrat too low"; }
        };
};
std::ostream &operator<<(std::ostream &o, Bureaucrat const &src);

#endif