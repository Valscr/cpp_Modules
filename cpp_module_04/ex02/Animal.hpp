/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:06:42 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/17 09:18:48 by valentin         ###   ########.fr       */
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
    protected:
        Animal();
        Animal(std::string name);
    public:
        virtual ~Animal();
        Animal& operator=(const Animal& src);
        Animal(const Animal& src);
        virtual void makeSound() const;
        std::string getType(void) const;
};

#endif