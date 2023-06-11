/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:33:40 by valentin          #+#    #+#             */
/*   Updated: 2023/06/11 12:29:33 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc < 2)
        return (0);
    try
    {
        PMergeMe pmerge(argc, argv);
        pmerge.Sort();
        std::cout << pmerge;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what();
        return (1);
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Erreur : Le nombre est hors de la plage valide pour un int." << std::endl;
    }
    return (0);
}