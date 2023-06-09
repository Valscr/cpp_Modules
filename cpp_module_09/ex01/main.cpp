/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:29:43 by valentin          #+#    #+#             */
/*   Updated: 2023/06/09 20:23:51 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    RPN rpn(argv[1]);
    try
    {
        rpn.calculate();
        std::cout << rpn;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what();
        return (1);
    }
    return (0);
}