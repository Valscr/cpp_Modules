/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:57:38 by vescaffr          #+#    #+#             */
/*   Updated: 2023/03/06 11:36:04 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; ++i)
    {
        std::string str(argv[i]);
        for (int j = 0; j < str.length(); ++j)
            str[j] = std::toupper(str[j]);
        std::cout << str;
    }
    std::cout << std::endl;
    return 0;
}
