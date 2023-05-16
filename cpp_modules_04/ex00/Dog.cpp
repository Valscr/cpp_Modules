/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:05:02 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/16 17:36:14 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Constructor is called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor is called" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "Woooof!" << std::endl;
}
