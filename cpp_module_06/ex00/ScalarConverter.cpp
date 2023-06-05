/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:57:22 by valentin          #+#    #+#             */
/*   Updated: 2023/06/06 00:23:20 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    this->_c = '\0';
    this->_n = 0;
    this->_f = 0;
    this->_d = 0;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
    *this = src;
}

int    ScalarConverter::getI(void) const
{
    return this->_n;
}

float    ScalarConverter::getF(void) const
{
    return this->_f;
}

double    ScalarConverter::getD(void) const
{
    return this->_d;
}

char    ScalarConverter::getC(void) const
{
    return this->_c;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
    if (this != &src)
    {
        this->_n = src.getI();
        this->_f = src.getF();
        this->_c = src.getC();
        this->_d = src.getD();
    }
    return *this;
}

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

void ScalarConverter::set(std::string str)
{
    this->number = str;
    if (str.length() == 1 && std::isalpha(str[0]) && std::isprint(str[0]))
        this->_type = "CHAR";
    else if (isFloat(str))
        this->_type = "FLOAT";
    else if (isInt(str))
        this->_type = "INT";
   else if (isDouble(str))
        this->_type = "DOUBLE";
}

int ScalarConverter::is_possible()
{
    try
    {
        if (this->_type == "INT")
            _n = std::stoi(this->number);
        else if (this->_type == "FLOAT")
            _f = std::stof(this->number);
        else if (this->_type == "DOUBLE")
            _d = std::stod(this->number);
    }
    catch (std::exception& e)
    {
        return true;
    }
    return false;
}

int    ScalarConverter::no_litteral() const
{
    if (this->number == "nan" || this->number == "nanf" || this->number == "+inf"
        || this->number == "-inf" || this->number == "+inff" || this->number == "-inff")
        return true;
    return false;
}

void    ScalarConverter::display_int() const
{ 
    if (this->_type.empty())
        std::cout << "non displayable";
    else if (no_litteral())
        std::cout << "Impossible";
    else
        std::cout << this->_n;
    std::cout << std::endl;
}

void    ScalarConverter::display_char() const
{
    if (no_litteral())
        std::cout << "Impossible";
    else if (!std::isprint(this->_c))
        std::cout << "non displayable";
    else
        std::cout << "'" << this->_c << "'";
    std::cout << std::endl;
}

void    ScalarConverter::display_float() const
{
    if (this->number == "nanf" || this->number == "+inff" || this->number == "-inff")
        std::cout << this->number;
    else if (no_litteral())
        std::cout << this->number << "f";
    else if (this->_type == "INT" || this->_type == "CHAR" || (this->_type == "FLOAT" && std::fmod(this->_f, 1) == 0) || (this->_type == "DOUBLE" && std::fmod(this->_d, 1) == 0))
        std::cout << this->_f << ".0f";
    else if (this->_type.empty())
        std::cout << "non displayable";
    else
        std::cout << this->_f << "f";
    std::cout << std::endl;
}

void    ScalarConverter::display_double() const
{
    if (this->number == "nanf")
        std::cout << "nan";
    else if (this->number == "+inff")
        std::cout << "+inf";
    else if (this->number == "-inff")
        std::cout << "-inf";
    else if (no_litteral())
        std::cout << this->number;
    else if (this->_type == "INT" || this->_type == "CHAR")
        std::cout << this->_d << ".0";
    else if (this->_type == "FLOAT")
        std::cout << this->number.substr(0, this->number.length() - 1);
    else if (this->_type.empty())
        std::cout << "non displayable";
    else
        std::cout << this->number;
    std::cout << std::endl;
}

void ScalarConverter::convert()
{
    if (is_possible())
        return ;
    if (this->_type == "CHAR")
    {
        _c = this->number[0];
        _n = static_cast< int >( _c );
        _f = static_cast< float >( _c );
        _d = static_cast< double >( _c );
    }
    else if (this->_type == "INT")
    {
        _n = std::stoi(this->number);
        _f = static_cast< float >( _n );
        _d = static_cast< double >( _n );
        _c = static_cast< char >( _n );
    }
    else if (this->_type == "FLOAT")
    {
        _f = std::stof(this->number);
        _n = static_cast< int >( _f );
        _d = static_cast< double >( _f );
        _c = static_cast< char >( _f );
    }
    else if (this->_type == "DOUBLE")
    {
        _d = std::stod(this->number);
        _n = static_cast< int >( _d );
        _f = static_cast< float >( _d );
        _c = static_cast< char >( _d );
    }
}

std::ostream&    operator<<(std::ostream& o, const ScalarConverter& src)
{
    o << "char: "; src.display_char();
    o << "int: "; src.display_int();
    o << "float: "; src.display_float();
    o << "double: "; src.display_double();
    return o;
}
