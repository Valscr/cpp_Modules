/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:06:42 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/24 16:28:24 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
    private:
        std::string type;
    public:
        Animal();
        Animal(std::string name);
        virtual ~Animal();
        Animal& operator=(const Animal& src);
        Animal(const Animal& src);
        virtual void makeSound() const = 0;
        std::string getType(void) const;
};

#endif