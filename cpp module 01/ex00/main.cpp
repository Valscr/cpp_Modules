/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:58:47 by valentin          #+#    #+#             */
/*   Updated: 2023/04/20 21:28:01 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string name;

    std::cout << "Enter a Zombie name :" << std::endl;
    std::cin >> name;
    Zombie *zombie = newZombie(name);
    zombie->announce();
    std::cout << std::endl << "randomChump execution :" << std::endl;
    randomChump("Darksidius");
    delete(zombie);
}