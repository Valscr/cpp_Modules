/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:23:12 by valentin          #+#    #+#             */
/*   Updated: 2023/06/02 22:25:42 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bureau1("bureau1", 1);
    Bureaucrat bureau2("bureau2", 0);
    Bureaucrat bureau3("bureau3", 151);

    std::cout << bureau1;
    std::cout << bureau2;
    std::cout << bureau3;

}