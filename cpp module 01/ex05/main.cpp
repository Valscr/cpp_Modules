/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:58:13 by vescaffr          #+#    #+#             */
/*   Updated: 2023/04/21 14:44:51 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    std::string level;
    Harl harl;
    
    while (1)
    {
        std::cout << "Enter a level :" << std::endl;
        std::cin >> level;
        harl.complain(level);
        if (std::cin.eof())
			return 0;
    }
}