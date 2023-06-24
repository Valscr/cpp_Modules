/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:33:28 by valentin          #+#    #+#             */
/*   Updated: 2023/06/23 16:27:30 by vescaffr         ###   ########.fr       */
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
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch (const std::exception& e) {
        try {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        } catch (const std::exception& e) {
            try {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}