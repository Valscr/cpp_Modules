/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:37:30 by valentin          #+#    #+#             */
/*   Updated: 2023/06/23 16:55:14 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base*   a = generate();
    Base*   b = generate();
    Base*   c = generate();
    Base*   d = generate();
    Base*   e = new D;

    std::cout << "a* = "; identify(a);
    std::cout << "a& = "; identify(*a); 
    std::cout << std::endl;
    std::cout << "b* = "; identify(b);
    std::cout << "b& = "; identify(*b); 
    std::cout << std::endl;
    std::cout << "c* = "; identify(c);
    std::cout << "c& = "; identify(*c);
    std::cout << std::endl;
    std::cout << "d* = "; identify(d);
    std::cout << "d& = "; identify(*d);
    std::cout << std::endl;
    std::cout << "d* = "; identify(e);
    std::cout << "d& = "; identify(*e);

    delete a;
    delete b;
    delete c;
    delete d;
    delete e;

    return (0);
}