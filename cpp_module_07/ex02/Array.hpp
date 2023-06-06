/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:22:24 by valentin          #+#    #+#             */
/*   Updated: 2023/06/06 16:26:16 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template < typename T >
class Array
{
    private:
        T* _tab;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& src);
        ~Array(void);
        unsigned int  getsize(void) const;
        T getTab(unsigned int i) const;
        Array& operator=(const Array& src);
        T& operator[](unsigned int index) const;
};

template < typename T >
Array<T>::Array()
{
    this->_tab = new T();
    this->_size = 1;
}

template < typename T >
Array<T>::Array(unsigned int n)
{
    this->_tab = new T[n];
    this->_size = n;
}

template < typename T >
T Array<T>::getTab(unsigned int i) const
{
    return (this->_tab[i]);
}

template < typename T >
Array<T>::Array(const Array& src) : _tab(new T[src.getsize()]), _size(src.getsize())
{
        for (unsigned int i = 0; i < this->_size; i++)
            this->_tab[i] = src.getTab(i);
};

template < typename T >
Array<T>::~Array(void)
{
    delete [] this->_tab;
}

template < typename T >
unsigned int  Array<T>::getsize(void) const
{
    return this->_size;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
    if (index >= this->_size)
        throw std::out_of_range("Index out of range");
    return this->_tab[index];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& src)
{
    if (this != &src )
    {
        delete [] this->_tab;
        this->_tab = new T[src.getsize()];
        this->_size = src.getsize();
        for (unsigned int i = 0; i < this->_size; i++)
            this->_tab[i] = src.getTab(i);
    }
    return *this;
}

template < typename T >
std::ostream& operator<<(std::ostream& o, const Array<T>& tab) {
    for (unsigned int i = 0; i < tab.getsize(); i++)
        o << tab[i] << " ";
    return o;
}
