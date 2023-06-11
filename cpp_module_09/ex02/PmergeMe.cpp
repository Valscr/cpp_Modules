/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:00:56 by valentin          #+#    #+#             */
/*   Updated: 2023/06/11 12:00:44 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PMergeMe::PMergeMe(int argc, char **argv)
{
    int i = 1;
    for (; argv[i]; i++)
    {
        for (int j = 0; argv[i][j]; j++)
            if (!std::isdigit(argv[i][j]))
                throw std::runtime_error("Error\n");
        if (std::stoi(argv[i]) < 0)
            throw std::runtime_error("Error\n");
    }
    i = 1;
    for (; argv[i]; i++)
    {
        this->_numbers_vec.push_back(std::stoi(argv[i]));
        this->_numbers_vec_before.push_back(std::stoi(argv[i]));
        this->_numbers_deq.push_back(std::stoi(argv[i]));
    }
    this->_duration_vec = 0;
    this->_duration_deq = 0;
    this->_size = argc - 1;
}

void PMergeMe::insertionSort_vector(std::vector<int>& vec)
{
    for (int i = 1; i < (int)vec.size(); ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

void PMergeMe::mergeInsertionSort_vector(std::vector<int>& vec, int threshold)
{
    if ((int)vec.size() <= threshold) {
        insertionSort_vector(vec);
        return;
    }

    int mid = vec.size() / 2;
    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());

    mergeInsertionSort_vector(left, threshold);
    mergeInsertionSort_vector(right, threshold);

    vec.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(vec));
}

void PMergeMe::insertionSort_deque(std::deque<int>& deq)
{
    for (int i = 1; i < (int)deq.size(); ++i) {
        int key = deq[i];
        int j = i - 1;
        while (j >= 0 && deq[j] > key) {
            deq[j + 1] = deq[j];
            --j;
        }
        deq[j + 1] = key;
    }
}

void PMergeMe::mergeInsertionSort_deque(std::deque<int>& deq, int threshold)
{
    if ((int)deq.size() <= threshold) {
        insertionSort_deque(deq);
        return;
    }

    int mid = deq.size() / 2;
    std::deque<int> left(deq.begin(), deq.begin() + mid);
    std::deque<int> right(deq.begin() + mid, deq.end());

    mergeInsertionSort_deque(left, threshold);
    mergeInsertionSort_deque(right, threshold);

    deq.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(deq));
}

void PMergeMe::Sort()
{
    clock_t startTime = clock();
    mergeInsertionSort_vector(this->_numbers_vec, this->_size / 2);
    clock_t endTime = clock();
    this->_duration_vec = static_cast<double>(endTime - startTime) / (double)CLOCKS_PER_SEC;
    startTime = clock();
    mergeInsertionSort_deque(this->_numbers_deq, this->_size / 2);
    endTime = clock();
    this->_duration_deq = static_cast<double>(endTime - startTime) / (double)CLOCKS_PER_SEC;
}

std::ostream&    operator<<(std::ostream& o, const PMergeMe& src)
{
    o << "Before :   ";
    std::vector<int> vec = src.getVector_start();
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        o << *it << " ";
    o << std::endl;
    o << "After :   ";
    vec = src.getVector_end();
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        o << *it << " ";
    o << std::endl;
    o << "Time to process a range of " << src.get_size() << " elements with std::vector : " << std::fixed << src.get_duration_vec() << " us" << std::endl;
    o << "Time to process a range of " << src.get_size() << " elements with std::deque : " << std::fixed << src.get_duration_deq() << " us" << std::endl;
    return o;
}

