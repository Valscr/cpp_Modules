/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:53:50 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/15 16:01:15 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "ClapTrap " << name << " is created!" << std::endl;
}

ClapTrap::ClapTrap()
{
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hit_points < 1)
    {
        std::cout << "ClapTrap " << this->name << " is already dead, no action possible!" << std::endl;
        return ;
    }
    if (this->energy_points < 1)
    {
        std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
        return;
    } 
    this->energy_points -= 1;
    std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attack_damage << " point(s) of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points < 1)
    {
        std::cout << "ClapTrap " << this->name << " is already dead, no action possible!" << std::endl;
        return ;
    }
    if (this->energy_points < 1)
    {
        std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
        return;
    } 
    this->hit_points -= amount;
    std::cout << "ClapTrap " << this->name << " take " << amount << " point(s) of damage!" << std::endl;
    if (this->hit_points < 1)
    {
        std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
    }
   
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points < 1)
    {
        std::cout << "ClapTrap " << this->name << " is already dead, no action possible!" << std::endl;
        return ;
    }
    if (this->energy_points < 1)
    {
        std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
        return;
    }
    this->energy_points -= 1;
    this->hit_points += amount;
    std::cout << "ClapTrap " << this->name << " take " << amount << " point(s) of repair!" << std::endl;
}
