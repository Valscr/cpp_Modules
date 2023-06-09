/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:25:25 by valentin          #+#    #+#             */
/*   Updated: 2023/06/09 11:47:17 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

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
        BitcoinExchange(const BitcoinExchange& src) {*this = src;};
        ~BitcoinExchange() {};
        float find_date_price(std::list<std::string> database);
        std::string getDate() const {return (this->_date);};
        float getValue() const {return (this->_value);};
        BitcoinExchange& operator=(const BitcoinExchange& src);
};

std::ostream&    operator<<(std::ostream& o, const BitcoinExchange& src);
bool isValidDate(int year, int month, int day);
bool compareDates(const std::string& date1, const std::string& date2);
#endif