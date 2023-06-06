/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:48:43 by valentin          #+#    #+#             */
/*   Updated: 2023/06/06 17:26:42 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
        
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<int> vect(tab, tab + sizeof(tab) / sizeof(int));
    std::list<int> list(tab, tab + sizeof(tab) / sizeof(int));

    int searchValue = std::atoi(argv[1]);
    bool vectfind = easyfind(vect, searchValue);
    bool listfind = easyfind(list, searchValue);
    if (vectfind == true)
        std::cout << "Value " << searchValue << " found in vector" << std::endl;
    else
        std::cout << "Value " << searchValue << " not found in vector" << std::endl;
    if (listfind == true)
        std::cout << "Value " << searchValue << " found in list" << std::endl;
    else
        std::cout << "Value " << searchValue << " not found in list" << std::endl;

    return 0;
}