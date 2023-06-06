/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:33:37 by valentin          #+#    #+#             */
/*   Updated: 2023/06/06 12:37:06 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>

class Base
{
    public:
        virtual ~Base() {};

};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif