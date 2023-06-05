/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:57:38 by valentin          #+#    #+#             */
/*   Updated: 2023/06/05 23:23:13 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
    private:
        char    _c;
        int     _n;
        float   _f;
        double  _d;
        std::string _type;
        std::string number;
        
    public:
        ScalarConverter();
        ~ScalarConverter();
        void set(std::string str);
        int isInt(std::string str);
        int isFloat(std::string str);
        int isDouble(std::string str);
        void convert();
        int is_possible();
        void display_int() const;
        int no_litteral() const;
        void display_char() const;
        void display_float() const;
        void display_double() const;
};
std::ostream&    operator<<(std::ostream& o, const ScalarConverter& src);

#endif