/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:04:05 by vescaffr          #+#    #+#             */
/*   Updated: 2023/04/21 13:26:11 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
