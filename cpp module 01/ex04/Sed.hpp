/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:48:12 by vescaffr          #+#    #+#             */
/*   Updated: 2023/04/21 13:50:40 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
 private:
 	std::string		infile;
    std::string     outfile;
 public:
	Sed(std::string filename);
    ~Sed();
    void    replace(std::string s1, std::string s2);
};

#endif