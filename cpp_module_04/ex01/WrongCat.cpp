/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:55:58 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/16 17:46:09 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat")
{
    std::cout << "WrongCat Constructor is called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor is called" << std::endl;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "Miaou!" << std::endl;
}
