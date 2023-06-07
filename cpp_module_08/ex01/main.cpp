/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:29:44 by valentin          #+#    #+#             */
/*   Updated: 2023/06/07 17:31:22 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try {
        std::cout << "--------- first test ------" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::cout << "--------- second test ------" << std::endl;
        std::srand(std::time(0));
        
        std::list<int> span1(10000);
        std::generate(span1.begin(), span1.end(), std::rand);

        Span span(span1.size());
        span.addlistNumber(span1.begin(), span1.end());
        unsigned int longest = span.longestSpan();
        unsigned int shortest = span.shortestSpan();

        std::cout << "Longest span: " << longest << std::endl;
        std::cout << "Shortest span: " << shortest << std::endl;
        }
    
    catch (const std::exception& e)
    {
        std::cout << "Eror: " << e.what() << std::endl;
    }
    return 0;
}
