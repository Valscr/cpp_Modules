/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:24:27 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/16 17:53:58 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    private:
        std::string type;

    public:
        WrongAnimal(std::string name);
        WrongAnimal();
        ~WrongAnimal();
        void makeSound() const;
        WrongAnimal(const WrongAnimal& src);
        WrongAnimal& operator=(const WrongAnimal& source);
        std::string getType(void) const;
};

#endif