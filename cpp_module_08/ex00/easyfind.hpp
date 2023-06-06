/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:26:07 by valentin          #+#    #+#             */
/*   Updated: 2023/06/06 17:26:28 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template < typename T >
bool    easyfind(T &a, int i)
{
    if (std::find(a.begin(), a.end(), i) != a.end())
        return true;
    return false;
}