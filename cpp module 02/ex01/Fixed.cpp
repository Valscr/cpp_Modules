/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:08:38 by valentin          #+#    #+#             */
/*   Updated: 2023/05/04 16:09:43 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
     ValueNumber = value << NumberBits;
}

Fixed::Fixed(const float n) : ValueNumber(std::roundf(n * (1 << NumberBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->ValueNumber = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->ValueNumber;
}

void    Fixed::setRawBits(int const raw)
{
    this->ValueNumber = raw;
}

float   Fixed::toFloat(void) const
{
    return static_cast<float>(this->getRawBits()) / (1 << NumberBits);
}

int     Fixed::toInt(void) const
{
    return this->ValueNumber >> NumberBits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
    o << i.toFloat();
    return o;
}
