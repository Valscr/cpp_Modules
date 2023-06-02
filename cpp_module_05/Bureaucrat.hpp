/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:23:01 by valentin          #+#    #+#             */
/*   Updated: 2023/06/02 22:24:48 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        std::string const name;
        unsigned int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, unsigned int grade);
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &src);
        Bureaucrat& operator=(const Bureaucrat &src);
        std::string getName(void) const;
        unsigned int getGrade(void) const;
        void    incrementGrade(unsigned int);
        void    decrementGrade(unsigned int);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade too high"; }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade too low"; }
        };
};
std::ostream &operator<<(std::ostream &o, Bureaucrat const &src);

#endif