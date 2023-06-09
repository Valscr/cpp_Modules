/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:23:22 by valentin          #+#    #+#             */
/*   Updated: 2023/06/09 12:05:00 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "invalid number of arguments" << std::endl;
        return (0);
    }
    std::ifstream fileinput(argv[1]);
    std::ifstream filedata("data.csv");
    if (fileinput.is_open() && filedata.is_open())
    {
        std::list<std::string> datacsv;
        std::string linedata;
        while (std::getline(filedata, linedata))
            datacsv.push_back(linedata);
        filedata.close();
        std::string lineinput;
        while (std::getline(fileinput, lineinput))
        {
            try {
                BitcoinExchange btc(lineinput);
                std::cout << btc;
                std::cout << btc.find_date_price(datacsv) << std::endl;
                }
                catch (const std::runtime_error& e)
                {
                    std::cout << e.what();
                    continue;
                }
        }
        filedata.close();
    }
    else
        std::cout << "Invalid input file" << std::endl;
    return (0);
}