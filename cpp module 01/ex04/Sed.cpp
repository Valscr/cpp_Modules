/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:48:02 by vescaffr          #+#    #+#             */
/*   Updated: 2023/04/21 13:49:36 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string filename) : infile(filename)
{
    this->outfile = this->infile + ".replace";
}

Sed::~Sed(void)
{
}

void            Sed::replace( std::string s1, std::string s2)
{
    std::ifstream   ifs(this->infile);
    if (ifs.is_open())
    {
        std::string content;
        if (std::getline(ifs, content, '\0'))
        {
            std::ofstream   ofs(this->outfile);
            size_t          pos = content.find(s1);
            while (pos != std::string::npos)
            {
                content.erase(pos, s1.length());
                content.insert(pos, s2);
                pos = content.find(s1);
            }
            ofs << content;
            ofs.close();
        }
        else {
            std::cerr << "Empty file found." << std::endl;
        }
        ifs.close();
    }
    else
    {
        std::cerr << "Unable to open the file." << std::endl;
        exit(1);
    }
}
