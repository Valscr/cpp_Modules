/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:15:22 by valentin          #+#    #+#             */
/*   Updated: 2023/04/21 01:25:11 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
 private:
 	Weapon*		weapon;
    std::string name;
 public:
	HumanB(std::string name);
    ~HumanB();
    void    setWeapon(Weapon& weapon);
    void    attack(void);
};