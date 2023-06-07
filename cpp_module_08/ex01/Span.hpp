/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:32:25 by valentin          #+#    #+#             */
/*   Updated: 2023/06/07 17:07:33 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <list>

class Span
{
    private:
        std::list<int>  _list;
        unsigned int    _N;
    public:
        Span(unsigned int N);
        ~Span();
        void addNumber(int n);
        void addlistNumber(std::list<int>::const_iterator itBegin, std::list<int>::const_iterator itEnd);
        unsigned int shortestSpan(void);
        unsigned int longestSpan(void);
        const std::list< int >* getList(void) const;
        unsigned int size() const;
        Span& operator=(Span const &src);
        Span(const Span& src);
};
std::ostream& operator<<(std::ostream& o, const Span& span);

#endif