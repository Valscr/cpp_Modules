/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:15:45 by valentin          #+#    #+#             */
/*   Updated: 2023/04/21 01:26:07 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
 private:
 	std::string		type;
 public:
	Weapon(std::string type);
    ~Weapon();
    const  std::string& getType(void);
    void   setType(std::string typenew);
};

#endif