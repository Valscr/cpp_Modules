/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:06:42 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/16 17:14:12 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    private:
        std::string type;

    public:
        Animal(std::string name);
        Animal();
        virtual ~Animal();
        Animal& operator=(const Animal& src);
        Animal(const Animal& src);
        virtual void makeSound() const;
        std::string getType(void) const;
};

#endif