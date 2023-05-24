/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:05:09 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/24 16:20:15 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Constructor is called" << std::endl;
    try
    {
        this->_brain = new Brain();
    }
    catch (const std::bad_alloc& e)
    {
        std::cout << "Memory Allocation is failed : " << e.what() << std::endl;
    }
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Cat Destructor is called" << std::endl;
   
}

void    Cat::makeSound(void) const
{
    std::cout << "Miaou!" << std::endl;
}
