/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:15:49 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/16 17:53:22 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete meta;
delete j;
delete i;

const WrongAnimal* Wronganimal = new WrongAnimal();
const WrongAnimal* Wrongcat = new WrongCat();
std::cout << Wrongcat->getType() << " " << std::endl;
Wrongcat->makeSound(); //will output the WrongAnimal sound!
delete Wronganimal;
delete Wrongcat;
return 0;
}