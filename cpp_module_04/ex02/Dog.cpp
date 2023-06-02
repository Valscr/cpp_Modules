/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:05:02 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/16 18:25:46 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Constructor is called" << std::endl;
    try
    {
        this->_brain = new Brain();
    }
    catch (const std::bad_alloc& e)
    {
        std::cout << "Memory Allocation is failed : " << e.what() << std::endl;
    }
}

Dog::~Dog()
{
    std::cout << "Dog Destructor is called" << std::endl;
    delete this->_brain;
}

void    Dog::makeSound(void) const
{
    std::cout << "Woooof!" << std::endl;
}
