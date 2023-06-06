/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:19:36 by valentin          #+#    #+#             */
/*   Updated: 2023/06/06 13:20:48 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void    swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T    min(T &a, T &b)
{
    if (a < b)
        return (a);
    return (b);
}

template <typename T>
T    max(T &a, T &b)
{
    if (a > b)
        return (a);
    return (b);
}
