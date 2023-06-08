/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:23:22 by valentin          #+#    #+#             */
/*   Updated: 2023/06/09 00:00:24 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <ctime>

class BitcoinExchange
{
    private:
        std::string _date;
        float _value;
    public:
        BitcoinExchange(std::string line);
        ~BitcoinExchange() {};
        void printline(void);
        float find_date_price(std::list<std::string> database);
};

bool isValidDate(int year, int month, int day) {
    std::tm timeinfo = {};
    timeinfo.tm_year = year - 1900;  // Année - 1900
    timeinfo.tm_mon = month - 1;     // Mois - 1 (Janvier = 0, Février = 1, ...)
    timeinfo.tm_mday = day;          // Jour

    // Convertir la structure tm en temps depuis l'époque
    std::time_t time = std::mktime(&timeinfo);

    // Vérifier si la date est valide
    // mktime peut ajuster les valeurs de la date si elles sont invalides
    // Donc, si les valeurs de la date ont été ajustées, cela signifie que la date est invalide
    if (timeinfo.tm_year != year - 1900 || timeinfo.tm_mon != month - 1 || timeinfo.tm_mday != day) {
        return false;
    }

    return true;
}

BitcoinExchange::BitcoinExchange(std::string line)
{
    int i = 0;
    for (; line[i] == ' '; i++) {}
    if(!std::isdigit(line[i]))
        throw std::runtime_error("");
    for (; std::isdigit(line[i]) || line[i] == '-'; i++) {}
    if (!isValidDate(std::stoi(line.substr(0, 4)), std::stoi(line.substr(5, 2)), std::stoi(line.substr(8, 2))))
        throw std::runtime_error("Error: bad input");
    this->_date = line.substr(0, i);
    for (; line[i] == ' '; i++) {}
    if (line[i] != '|')
        throw std::runtime_error("");
    i++;
    for (; line[i] == ' '; i++) {}
    if (line[i] != '-' && line[i] != '+' && !std::isdigit(line[i]))
        throw std::runtime_error("");
    if (!std::isdigit(line[line.size() - 1]))
        throw std::runtime_error("");
    if (std::stof(line.substr(i)) < 0.0 || std::stof(line.substr(i)) > 1000.0)
        throw std::runtime_error("");
    this->_value = std::stof(line.substr(i));
}

bool compareDates(const std::string& date1, const std::string& date2) {
    int year1 = std::stoi(date1.substr(0, 4));
    int month1 = std::stoi(date1.substr(5, 2));
    int day1 = std::stoi(date1.substr(8, 2));

    int year2 = std::stoi(date2.substr(0, 4));
    int month2 = std::stoi(date2.substr(5, 2));
    int day2 = std::stoi(date2.substr(8, 2));

    if (year1 < year2) {
        return true;
    } else if (year1 > year2) {
        return false;
    } else if (month1 < month2) {
        return true;
    } else if (month1 > month2) {
        return false;
    } else {
        return day1 < day2;
    }
}

float BitcoinExchange::find_date_price(std::list<std::string> database)
{
    std::string str = "2000-01-01";
    std::list<std::string>::iterator it = database.begin();
    it++;
    for (;it != database.end(); ++it)
    {
            if (compareDates(it->substr(0, 10), this->_date.substr(0, 10)) && compareDates(str.substr(0, 10), it->substr(0, 10)))
                str = *it;
    }
    return (std::stof(str.substr(11)) * this->_value);
}

void BitcoinExchange::printline(void)
{
    std::cout << this->_date << " => " << this->_value << " = ";
}

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
        std::list<std::string> datab;
        std::string line1;

        while (std::getline(filedata, line1))
            datab.push_back(line1);

        filedata.close();
        std::string line;
        while (std::getline(fileinput, line))
        {
            try {
                BitcoinExchange btc(line);
                btc.printline();
                std::cout << btc.find_date_price(datab) << std::endl;
                }
                catch (const std::runtime_error& e)
                {
                    continue;
                }
        }
        filedata.close();
    }
    else
        std::cout << "Invalid input file" << std::endl;
    return (0);
}