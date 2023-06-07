/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:32:32 by valentin          #+#    #+#             */
/*   Updated: 2023/06/07 17:07:38 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
    this->_N = N;
}

Span::~Span(void)
{
}

Span::Span(const Span& src)
{
    *this = src;
}

Span& Span::operator=(Span const &src)
{
    if (this != &src) 
    {
        this->_N = src._N;
        this->_list = src._list;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (_list.size() >= _N)
        throw std::out_of_range("Span::addNumber: list is full");
    _list.push_back(n);
}

void Span::addlistNumber(std::list<int>::const_iterator itBegin, std::list<int>::const_iterator itEnd)
{
    if (_list.size() >= _N)
        throw std::out_of_range("Span::addNumber: list is full");
    _list.insert(_list.end(), itBegin, itEnd);
}

unsigned int    Span::longestSpan(void)
{
    if (_list.size() == 1)
        throw std::out_of_range("Span::longestSpan: list has just one element");
    if (_list.size() == 0)
        throw std::out_of_range("Span::longestSpan: list is empty");
    return (*std::max_element(_list.begin(), _list.end()) - *std::min_element(_list.begin(), _list.end()));
}

unsigned int    Span::shortestSpan(void)
{
    unsigned int dif = longestSpan();
    if (_list.size() == 1)
        throw std::out_of_range("Span::longestSpan: list has just one element");
    if (_list.size() == 0)
        throw std::out_of_range("Span::longestSpan: list is empty");
      for (std::list<int>::const_iterator itI = _list.begin(); itI != _list.end(); ++itI)
    {
        for (std::list<int>::const_iterator itJ = std::next(itI); itJ != _list.end(); ++itJ)
        {
            unsigned int span = std::abs(*itJ - *itI);
            if (span < dif)
                dif = span;
        }
    }
    return (dif);
}

const std::list< int >* Span::getList(void) const
{
    return &_list;
}

std::ostream& operator<<(std::ostream& o, const Span& span)
{
    for (std::list<int>::const_iterator it = span.getList()->begin(); it != span.getList()->end(); ++it)
        o << *it << " ";
    return o;
}

unsigned int Span::size() const
{
    return _list.size();
}
