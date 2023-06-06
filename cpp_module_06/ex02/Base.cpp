/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:33:28 by valentin          #+#    #+#             */
/*   Updated: 2023/06/06 12:37:30 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void)
{
    static int i = time(0);
    srand(i++);
    int randomNumber = std::rand() % 3;
    if (randomNumber == 0)
        return (new A);
    else if (randomNumber == 1)
        return (new B);
    else
        return (new C);
    return 0;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "type unidentified" << std::endl;
}

void identify(Base& p)
{
    if (dynamic_cast<A*>(&p) != nullptr)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p) != nullptr)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p) != nullptr)
        std::cout << "C" << std::endl;
    else
        std::cout << "type unidentified" << std::endl;
    return ;
}