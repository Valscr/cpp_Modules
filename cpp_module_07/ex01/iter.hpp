/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:25:47 by valentin          #+#    #+#             */
/*   Updated: 2023/06/06 14:28:03 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template < typename T >
void    iter(T *tab, unsigned int size, void (*f)(T &))
{
   for (unsigned int i = 0; i < size; i++)
        f(tab[i]);
}

template < typename T >
void    display(T &a)
{
    std::cout << a << std::endl;
}
