/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:53:47 by valentin          #+#    #+#             */
/*   Updated: 2023/06/06 14:26:43 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int tabint[] = {1, 28, -1234, 10, 0};
    iter(tabint, 5, display);

    char tabchar[] = {'s', 'a', 'l', 'u', 't'};
    iter(tabchar, 5, display);

    std::string tabstr[] = {"hey", "salut", "comment", "ca", "va"};
    iter(tabstr, 5, display);

    double tabdouble[] = {1.2, 3.4, 5.6, 7.8, 9.0};
    iter(tabdouble, 5, display);
    
    return (0);
}