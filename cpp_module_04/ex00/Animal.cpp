/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:05:30 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/16 17:14:02 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Constructor is called" << std::endl;
}

Animal::Animal(std::string name)
{
    this->type = name;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor is called" << std::endl;
}

void    Animal::makeSound(void) const
{
    std::cout << "Animal makeSound is called" << std::endl;
}

std::string     Animal::getType(void) const
{
    return this->type;
}

Animal& Animal::operator=(const Animal& src)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &src)
        this->type = src.type;
    return *this;
}

Animal::Animal(const Animal& src)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}