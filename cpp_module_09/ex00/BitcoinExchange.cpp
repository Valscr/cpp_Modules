/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:25:15 by valentin          #+#    #+#             */
/*   Updated: 2023/07/25 12:44:19 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int ConvertToInt(const std::string& str)
{
    std::istringstream iss(str);
    int value;
    if (!(iss >> value))
        throw std::runtime_error("");
    return value;
}

float ConvertToFloat(const std::string& str)
{
    std::istringstream iss(str);
    float value;
    if (!(iss >> value))
        throw std::runtime_error("");
    return value;
}

BitcoinExchange::BitcoinExchange(std::string line)
{
    int i = 0;
    for (; line[i] == ' '; i++) {}
    if(!std::isdigit(line[i]))
        throw std::runtime_error("");
    for (; std::isdigit(line[i]) || line[i] == '-'; i++) {}
    if (!isValidDate(ConvertToInt(line.substr(0, 4)), ConvertToInt(line.substr(5, 2)), ConvertToInt(line.substr(8, 2))))
        throw std::runtime_error("Error: bad input => " + line.substr(0, i) + "\n");
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
    if (ConvertToFloat(line.substr(i)) < 0.0)
        throw std::runtime_error("Error: not a positive number.\n");
    if (ConvertToFloat(line.substr(i)) > 1000.0)
        throw std::runtime_error("Error: too large a number.\n");
    this->_value = ConvertToFloat(line.substr(i));
}

float BitcoinExchange::find_date_price(std::list<std::string> database)
{
    std::list<std::string>::iterator it = database.begin();
    it++;
    std::string str = it->substr(0, 10);
    for (;it != database.end(); ++it)
    {
            if (compareDates(it->substr(0, 10), this->_date.substr(0, 10)) && compareDates(str.substr(0, 10), it->substr(0, 10)))
                str = *it;
    }
    it = database.begin();
    it++;
    if (str == it->substr(0, 10))
        throw std::runtime_error("Error: no price known at this date => " + this->_date.substr(0, 10) + "\n");
    std::cout << *this;
    return (ConvertToFloat(str.substr(11)) * this->_value);
}

std::ostream&    operator<<(std::ostream& o, const BitcoinExchange& src)
{
    o << src.getDate(); o << " => "; 
    o << src.getValue(); o << " = ";
    return o;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this != &src)
    {
        this->_date = src.getDate();
        this->_value = src.getValue();
    }
    return *this;
}

bool compareDates(const std::string& date1, const std::string& date2)
{
    int year1 = ConvertToInt(date1.substr(0, 4));
    int month1 = ConvertToInt(date1.substr(5, 2));
    int day1 = ConvertToInt(date1.substr(8, 2));

    int year2 = ConvertToInt(date2.substr(0, 4));
    int month2 = ConvertToInt(date2.substr(5, 2));
    int day2 = ConvertToInt(date2.substr(8, 2));

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

bool isValidDate(int year, int month, int day)
{
    std::tm timeinfo = {};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;

    std::mktime(&timeinfo);

    if (timeinfo.tm_year != year - 1900 || timeinfo.tm_mon != month - 1 || timeinfo.tm_mday != day) {
        return false;
    }

    return true;
}

