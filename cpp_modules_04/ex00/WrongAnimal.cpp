/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:24:11 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/24 16:19:23 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name)
{
    std::cout << "WrongAnimal Constructor is called" << std::endl;
    this->type = name;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor is called" << std::endl;
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal makeSound is called" << std::endl;
}

std::string     WrongAnimal::getType(void) const
{
    return this->type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& source)
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &source)
        this->type = source.type;
    return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = src.type;
}
