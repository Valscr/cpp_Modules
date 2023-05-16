/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:03:09 by vescaffr          #+#    #+#             */
/*   Updated: 2023/05/16 18:26:28 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        ~Brain();
        Brain& Brain::operator=(const Brain& src);
        Brain::Brain(const Brain& src);
};

#endif