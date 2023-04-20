/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:15:03 by valentin          #+#    #+#             */
/*   Updated: 2023/04/21 01:25:05 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
 private:
 	Weapon&		weapon;
    std::string name;
 public:
	HumanA(std::string name, Weapon& weapon);
    ~HumanA();
    void attack(void);
};
