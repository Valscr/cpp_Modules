/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:05:09 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/16 16:12:34 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Constructor is called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor is called" << std::endl;
}

void    Cat::makeSound(void) const
{
    std::cout << "Miaou!" << std::endl;
}
