/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:47:22 by valentin          #+#    #+#             */
/*   Updated: 2023/07/24 14:34:33 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string operation)
{
    this->_operation = operation;
    this->_result = 0;
}

void RPN::calculate()
{
    std::stack<int> operandStack;
    int operand1;
    int operand2;
    int i = 0;
    while (this->_operation[i])
    {
        if (isdigit(this->_operation[i]) && !std::isdigit(this->_operation[i + 1]))
            operandStack.push(std::atoi(&this->_operation[i]));
        else if (this->_operation [i] == '-' || this->_operation[i] == '+' || this->_operation[i] == '*' || this->_operation[i] == '/')
        {
            if (operandStack.size() >= 2)
            {
                operand2 = operandStack.top();
                operandStack.pop();
                operand1 = operandStack.top();
                operandStack.pop();
            }
            else
                throw std::runtime_error("Error\n");
            if (this->_operation[i] == '+')
                operandStack.push(operand1 + operand2);
            else if (this->_operation[i] == '-')
                operandStack.push(operand1 - operand2);
            else if (this->_operation[i] == '*')
                operandStack.push(operand1 * operand2);
            else if (this->_operation[i] == '/')
                operandStack.push(operand1 / operand2);
        }
        else if (this->_operation[i] != ' ')
            throw std::runtime_error("Error\n");
        i++;
    }
    if (operandStack.size() == 1)
        this->_result = operandStack.top();
    else if (operandStack.size() > 1)
        throw std::runtime_error("The stack contains more than one number\n");
    else
        throw std::runtime_error("Error\n");
    return ;
}

int RPN::getResult() const
{
    return (this->_result);
}

std::string RPN::getOperation() const
{
    return (this->_operation);
}

std::ostream&    operator<<(std::ostream& o, const RPN& src)
{
    o << src.getResult() << std::endl; 
    return o;
}

RPN& RPN::operator=(const RPN& src)
{
    if (this != &src)
    {
        this->_operation = src.getOperation();
        this->_result = src.getResult();
    }
    return *this;
}