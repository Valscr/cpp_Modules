/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:57:38 by valentin          #+#    #+#             */
/*   Updated: 2023/06/25 00:36:10 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

class ScalarConverter
{
    private:
        ScalarConverter() {};
        
    public:
        ~ScalarConverter() {};
        static std::string set(std::string str);
        static int isInt(std::string str);
        static int isFloat(std::string str);
        static int isDouble(std::string str);
        static void convert(std::string str);
        static int is_possible(std::string type, std::string number);
        static void display_int(int n, std::string number, std::string type);
        static int no_litteral(std::string number);
        static void display_char(char c, std::string number);
        static void display_float(float f, std::string number, std::string type);
        static void display_double(double d, std::string number, std::string type);
        static double ConvertToDouble(const std::string& str);
        static float ConvertToFloat(const std::string& str);
        static int ConvertToInt(const std::string& str);
};
#endif