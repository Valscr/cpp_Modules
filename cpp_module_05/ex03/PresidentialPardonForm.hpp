/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:09:07 by valentin          #+#    #+#             */
/*   Updated: 2023/06/05 13:12:22 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:
        std::string _target;
        
    public:
       PresidentialPardonForm(std::string target);
       ~PresidentialPardonForm();
       void execute(const Bureaucrat& src) const;
       PresidentialPardonForm& operator=(PresidentialPardonForm& src);
       PresidentialPardonForm(const PresidentialPardonForm& src);
};

#endif