/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:37:30 by valentin          #+#    #+#             */
/*   Updated: 2023/06/06 12:38:54 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base*   a = generate();
    Base*   b = generate();
    Base*   c = generate();
    Base*   d = generate();

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

    delete a;
    delete b;
    delete c;
    delete d;

    return (0);
}