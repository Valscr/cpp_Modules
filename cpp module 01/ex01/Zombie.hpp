/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:23:52 by valentin          #+#    #+#             */
/*   Updated: 2023/04/20 21:52:21 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
 private:
 	std::string		name;
 public:
	Zombie();
    ~Zombie();
    void announce(void);
    void setName(std::string name);
};

Zombie *newZombie(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif