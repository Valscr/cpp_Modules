/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:04:05 by vescaffr          #+#    #+#             */
/*   Updated: 2023/04/21 13:50:54 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: Wrong number of arguments\n" << std::endl;
        return 1;
    }
    Sed sed1(argv[1]);
    sed1.replace(argv[2], argv[3]);
    return 0;
}
