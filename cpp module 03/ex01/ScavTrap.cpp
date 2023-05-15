/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:22:09 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/15 21:41:26 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap " << name << " is created!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is in Gate Keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hit_points < 1)
    {
        std::cout << "ScavTrap " << this->name << " is already dead, no action possible!" << std::endl;
        return ;
    }
    if (this->energy_points < 1)
    {
        std::cout << "ScavTrap " << this->name << " is out of energy!" << std::endl;
        return;
    } 
    this->energy_points -= 1;
    std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->attack_damage << " point(s) of damage!" << std::endl;
}