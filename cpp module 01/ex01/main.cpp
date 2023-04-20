/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:34:52 by valentin          #+#    #+#             */
/*   Updated: 2023/04/20 21:56:55 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string name;
    int N;

    std::cout << "Enter a Zombie name :" << std::endl;
    std::cin >> name;
    std::cout << "Enter a number of Zombies :" << std::endl;
    std::cin >> N;
    Zombie *zombie = zombieHorde(N, name);
    for (int i = 0; i < N; i++)
        zombie[i].announce();
     delete [] zombie;
     return (0);
}