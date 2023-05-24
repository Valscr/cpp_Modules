/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:14:03 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/24 14:11:24 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain Constructor is called, Brain is created" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Brain Destructor is called" << std::endl;
}

Brain& Brain::operator=(const Brain& src)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &src)
    {
        for( int i = 0; i < 100; i++ )
            this->_ideas[i] = src._ideas[i];
    }
    return *this;
}

Brain::Brain(const Brain& src)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
}