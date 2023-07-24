/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:01:09 by valentin          #+#    #+#             */
/*   Updated: 2023/07/24 14:51:59 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <ctime>
#include <sstream>

class PMergeMe
{
    private:
        std::vector<int> _numbers_vec_before;
        std::vector<int> _numbers_vec;
        std::deque<int> _numbers_deq;
        double  _duration_deq;
        int     _size;
        double  _duration_vec;
    public:
        PMergeMe(int argc, char **argv);
        ~PMergeMe() {};
        PMergeMe& operator=(const PMergeMe& src);
        PMergeMe(const PMergeMe& src) {*this = src;};
        void insertionSort_vector(std::vector<int>& vec);
        void mergeInsertionSort_vector(std::vector<int>& vec, int threshold);
        void insertionSort_deque(std::deque<int>& deq);
        void mergeInsertionSort_deque(std::deque<int>& deq, int threshold);
        void Sort();
        std::vector<int> getVector_start() const {return this->_numbers_vec_before;};
        std::vector<int> getVector_end() const {return this->_numbers_vec;};
        std::deque<int> getDeque_end() const {return this->_numbers_deq;};
        int get_size() const {return this->_size;};
        double get_duration_vec() const {return this->_duration_vec;};
        double get_duration_deq() const {return this->_duration_deq;};
};

std::ostream&    operator<<(std::ostream& o, const PMergeMe& src);

#endif