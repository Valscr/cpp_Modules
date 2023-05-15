/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:53:50 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/15 17:35:18 by vescaffr         ###   ########.fr       */
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

ClapTrap&   ClapTrap::operator=( const ClapTrap& rhs )
{
    this->name = rhs.name;
    this->hit_points = rhs.hit_points;
    this->energy_points = rhs.energy_points;
    this->attack_damage = rhs.attack_damage;
    std::cout << "[ ClapTrap ] - " << this->name << " has been copied with copy assignment operator." << std::endl;
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
