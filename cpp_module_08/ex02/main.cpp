/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:36:09 by valentin          #+#    #+#             */
/*   Updated: 2023/06/08 16:02:15 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << "----------- test stack -----------" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    
    std::cout << "------------ test list ------------" << std::endl;
    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    std::cout << l.back() << std::endl;
    l.pop_back();
    std::cout << l.size() << std::endl;
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);
    std::list<int>::iterator list_it = l.begin();
    std::list<int>::iterator list_ite = l.end();
    while (list_it != list_ite)
    {
    std::cout << *list_it << std::endl;
    ++list_it;
    }
    return 0;
}