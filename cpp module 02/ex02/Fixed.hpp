/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:08:47 by valentin          #+#    #+#             */
/*   Updated: 2023/05/04 16:10:46 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 ValueNumber;
        static const int    NumberBits = 8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float n);
        Fixed(const Fixed &rhs);
        Fixed& operator=(const Fixed &rhs);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif