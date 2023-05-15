/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:25:07 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/15 22:46:43 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap " << name << " is created!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (this->energy_points < 1)
    {
        std::cout << "FlagTrap " << this->name << " is out of energy!" << std::endl;
        return;
    } 
    std::cout << "FragTrap " << this->name << " request a high fives!" << std::endl;
    this->energy_points -= 1;
}