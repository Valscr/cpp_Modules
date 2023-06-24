/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:57:22 by valentin          #+#    #+#             */
/*   Updated: 2023/06/25 00:53:17 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int ScalarConverter::isInt(std::string str)
{
    int i = 0;
    if (str.empty())
        return 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    if (str[i] == '\0')
        return (0);
    for(; str[i]; i++)
        if (!std::isdigit(str[i]))
            return (0);
    return (1);
}

int ScalarConverter::isFloat(std::string str)
{
    int f = 0;
    int i = 0;
    if (str.empty())
        return 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    if (str[i] == '\0')
        return (0);
    for(; str[i + 1]; i++)
    {
        if (!std::isdigit(str[i]) && str[i] != '.')
            return (0);
        if (str[i] == '.')
            f++;
    }
    if (str[i] != 'f' || f != 1)
        return (0);
    return (1);
}

int ScalarConverter::isDouble(std::string str)
{
    int f = 0;
    int i = 0;
    if (str.empty())
        return 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    if (str[i] == '\0')
        return (0);
    for(; str[i]; i++)
    {
        if (!std::isdigit(str[i]) && str[i] != '.')
            return (0);
        if (str[i] == '.')
            f++;
    }
    if (f != 1)
        return (0);
    return (1);
}

int ScalarConverter::ConvertToInt(const std::string& str)
{
    std::istringstream iss(str);
    int value;
    if (!(iss >> value))
        throw std::runtime_error("Error: not a valid int\n");
    return value;
}

float ScalarConverter::ConvertToFloat(const std::string& str)
{
    std::istringstream iss(str);
    float value;
    if (!(iss >> value))
        throw std::runtime_error("Error: not a valid float\n");
    return value;
}

double ScalarConverter::ConvertToDouble(const std::string& str)
{
    std::istringstream iss(str);
    double value;
    if (!(iss >> value))
        throw std::runtime_error("Error: not a valid double\n");
    return value;
}

std::string ScalarConverter::set(std::string str)
{
    std::string type;
    if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]))
        type = "CHAR";
    else if (isFloat(str))
        type = "FLOAT";
    else if (isInt(str))
        type = "INT";
    else if (isDouble(str))
        type = "DOUBLE";
    else if (ScalarConverter::no_litteral(str))
        type = "LITTERAL";
    else
        std::cout << "Error: not a valid input" << std::endl;
    return (type);
}

int ScalarConverter::is_possible(std::string type, std::string number)
{
    try
    {
        if (type == "INT")
            ConvertToInt(number);
        else if (type == "FLOAT")
            ConvertToFloat(number.substr(0, number.length() - 1));
        else if (type == "DOUBLE")
            ConvertToDouble(number);
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
        return true;
    }
    return false;
}

int    ScalarConverter::no_litteral(std::string number)
{
    if (number == "nan" || number == "nanf" || number == "+inf"
        || number == "-inf" || number == "+inff" || number == "-inff")
        return true;
    return false;
}

void    ScalarConverter::display_int(int n, std::string number, std::string type)
{  
    if (no_litteral(number))
        std::cout << "Impossible";
    else if (type.empty())
        std::cout << "non displayable";
    else
        std::cout << n;
    std::cout << std::endl;
}

void    ScalarConverter::display_char(char c, std::string number)
{
    if (no_litteral(number))
        std::cout << "Impossible";
    else if (!std::isprint(c))
        std::cout << "non displayable";
    else
        std::cout << "'" << c << "'";
    std::cout << std::endl;
}

void    ScalarConverter::display_float(float f, std::string number, std::string type)
{
    if (number == "nanf" || number == "+inff" || number == "-inff")
        std::cout << number;
    else if (no_litteral(number))
        std::cout << number << "f";
    else if (type == "INT" || type == "CHAR" || (type == "FLOAT" && std::fmod(f, 1) == 0))
        std::cout << f << ".0f";
    else if (type.empty())
        std::cout << "non displayable";
    else
        std::cout << f << "f";
    std::cout << std::endl;
}

void    ScalarConverter::display_double(double d, std::string number, std::string type)
{
    if (number == "nanf")
        std::cout << "nan";
    else if (number == "+inff")
        std::cout << "+inf";
    else if (number == "-inff")
        std::cout << "-inf";
    else if (no_litteral(number))
        std::cout << number;
    else if (type == "INT" || type == "CHAR")
        std::cout << d << ".0";
    else if (type == "FLOAT")
        std::cout << number.substr(0, number.length() - 1);
    else if (type.empty())
        std::cout << "non displayable";
    else
        std::cout << number;
    std::cout << std::endl;
}

int ScalarConverter::convert(std::string str)
{
    std::string type;
    type = set(str);
    if (type.empty() || is_possible(type, str))
        return (0);
    if (type == "CHAR" || type == "LITTERAL")
    {
        std::cout << "char: "; display_char(str[0], str);
        std::cout << "int: "; display_int(static_cast< int >(str[0]), str, type);
        std::cout << "float: "; display_float(static_cast< float >(str[0]), str, type);
        std::cout << "double: "; display_double(static_cast< double >(str[0]), str, type);
    }
    else if (type == "INT")
    {
        std::cout << "char: "; display_char(static_cast< char >(ConvertToInt(str)), str);
        std::cout << "int: " <<  ConvertToInt(str) << std::endl;
        std::cout << "float: "; display_float(static_cast< float >(ConvertToInt(str)), str, type);
        std::cout << "double: "; display_double(static_cast< double >(ConvertToInt(str)), str, type);
    }
    else if (type == "FLOAT")
    {
        std::cout << "char: "; display_char(static_cast< char >(ConvertToFloat(str.substr(0, str.length() - 1))), str);
        std::cout << "int: "; display_int(static_cast< int >(ConvertToFloat(str.substr(0, str.length() - 1))), str, type);
        std::cout << "float: "; display_float(ConvertToFloat(str.substr(0, str.length() - 1)), str, type);
        std::cout << "double: "; display_double(static_cast< double >(ConvertToFloat(str.substr(0, str.length() - 1))), str, type);
    }
    else if (type == "DOUBLE")
    {
        std::cout << "char: "; display_char(static_cast< char >(ConvertToDouble(str)), str);
        std::cout << "int: "; display_int(static_cast< int >(ConvertToDouble(str)), str, type);
        std::cout << "float: "; display_float(static_cast< float >(ConvertToDouble(str)), str, type);
        std::cout << "double: " << ConvertToDouble(str) << std::endl;
    }
    return (1);
}
