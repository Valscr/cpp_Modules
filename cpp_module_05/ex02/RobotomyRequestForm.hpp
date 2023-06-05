/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:38:57 by valentin          #+#    #+#             */
/*   Updated: 2023/06/05 12:59:29 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
    private:
        std::string _target;
        
    public:
       RobotomyRequestForm(std::string target);
       ~RobotomyRequestForm();
       void execute(const Bureaucrat& src) const;
       RobotomyRequestForm& operator=(RobotomyRequestForm& src);
       RobotomyRequestForm(const RobotomyRequestForm& src);
};

#endif