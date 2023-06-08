/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:23:45 by valentin          #+#    #+#             */
/*   Updated: 2023/06/08 15:32:36 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <deque>

template< typename T, class Container = std::deque< T > > 
class MutantStack : public std::stack< T, Container >
{
    public:
        MutantStack() {};
        ~MutantStack() {};
        MutantStack(const MutantStack& src) {*this = src;};
        MutantStack&    operator=(const MutantStack& src) {
        std::stack< T, Container >::operator=(src);
        return *this;};
        
        typedef typename Container::iterator    iterator;
        iterator    begin(void) {return this->c.begin();};
        iterator    end(void) {return this->c.end();};
};