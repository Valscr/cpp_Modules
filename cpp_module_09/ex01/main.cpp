/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:29:43 by valentin          #+#    #+#             */
/*   Updated: 2023/06/09 19:39:45 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include <sstream>

int evaluatePostfixExpression(const std::string& operation)
{
    std::stack<int> operandStack;
    int operand1;
    int operand2;
    int i = 0;
    while (operation[i])
    {
        if (isdigit(operation[i]) && !std::isdigit(operation[i + 1]))
            operandStack.push(std::stoi(&operation[i]));
        else if (operation [i] == '-' || operation[i] == '+' || operation[i] == '*' || operation[i] == '/')
        {
            operand2 = operandStack.top();
            operandStack.pop();
            operand1 = operandStack.top();
            operandStack.pop();
            
            if (operation[i] == '+')
                operandStack.push(operand1 + operand2);
            else if (operation[i] == '-')
                operandStack.push(operand1 - operand2);
            else if (operation[i] == '*')
                operandStack.push(operand1 * operand2);
            else if (operation[i] == '/')
                operandStack.push(operand1 / operand2);
        }
        else if (operation[i] != ' ')
        {
            throw std::runtime_error("Error\n");
            return (-1);
        }
        i++;
    }
    return (operandStack.top());
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (1);
    std::stack<std::string> stack;
    try {
    std::cout << evaluatePostfixExpression(argv[1]) << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what();
        return (1);
    }
    return (0);
}