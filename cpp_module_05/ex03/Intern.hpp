/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:47:20 by valentin          #+#    #+#             */
/*   Updated: 2023/06/05 15:19:48 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern& operator=(const Intern& src);
        Intern(const Intern& src);
        Form* makeForm(std::string name_form, std::string target);
};

#endif