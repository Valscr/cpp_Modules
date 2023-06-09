/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:53:50 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/15 19:33:01 by valentin         ###   ########.fr       */
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

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& source)
{
    this->name = source.name;
    this->hit_points = source.hit_points;
    this->energy_points = source.energy_points;
    this->attack_damage = source.attack_damage;
    return *this;
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
