/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:57:03 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/15 13:57:34 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
     ClapTrap clap("Val");

    clap.attack("Enemy");
    clap.takeDamage(3);
    clap.beRepaired(2);
    clap.attack("Enemy1");
    clap.takeDamage(18);
    clap.attack("Enemy2");
}