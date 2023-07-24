/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:47:14 by valentin          #+#    #+#             */
/*   Updated: 2023/07/24 14:35:24 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <algorithm>

class RPN
{
    private:
        std::string _operation;
        int _result;
    public:
        RPN(std::string operation);
        ~RPN() {};
        RPN(const RPN& src) {*this = src;};
        RPN& operator=(const RPN& src);
        void calculate();
        std::string getOperation() const;
        int getResult() const;
};
std::ostream&    operator<<(std::ostream& o, const RPN& src);

#endif