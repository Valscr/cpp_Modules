/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:33:37 by valentin          #+#    #+#             */
/*   Updated: 2023/06/23 16:23:10 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>

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

class D : public Base
{
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif