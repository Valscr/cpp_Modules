/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:29:59 by valentin          #+#    #+#             */
/*   Updated: 2023/06/06 16:26:11 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<int> tab(5);
    for (unsigned int i = 0; i < tab.getsize(); i++)
        tab[i] = i;

    std::cout << "Array: " << tab << std::endl;

    Array<int> tabcopy = tab;
    tabcopy[2] = 10;

    std::cout << "Original Array: " << tab << std::endl;
    std::cout << "Copied Array: " << tabcopy << std::endl;

    return 0;
}