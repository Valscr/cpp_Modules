/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:57:03 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/15 21:46:30 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
     ClapTrap clap("Clap");
     ScavTrap scav("Scav");
   
    clap.attack("Enemy");
    clap.takeDamage(3);
    clap.beRepaired(2);
    clap.attack("Enemy1");
    clap.takeDamage(18);
    clap.attack("Enemy2");

    scav.attack("Enemy");
    scav.takeDamage(3);
    scav.beRepaired(2);
    scav.attack("Enemy1");
    scav.takeDamage(18);
    scav.attack("Enemy2");
}