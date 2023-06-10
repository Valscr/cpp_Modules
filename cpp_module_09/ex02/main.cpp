/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:33:40 by valentin          #+#    #+#             */
/*   Updated: 2023/06/10 22:40:05 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <ctime>

void insertionSort_deque(std::deque<int>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

void mergeInsertionSort_deque(std::deque<int>& vec, int threshold) {
    if (vec.size() <= threshold) {
        insertionSort_deque(vec);
        return;
    }

    int mid = vec.size() / 2;
    std::deque<int> left(vec.begin(), vec.begin() + mid);
    std::deque<int> right(vec.begin() + mid, vec.end());

    mergeInsertionSort_deque(left, threshold);
    mergeInsertionSort_deque(right, threshold);

    vec.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(vec));
}

void insertionSort_vector(std::vector<int>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

void mergeInsertionSort_vector(std::vector<int>& vec, int threshold)
{
    if (vec.size() <= threshold) {
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

int main (int argc, char **argv)
{
    if (argc < 2)
        return (0);
    std::vector<int> numbers_vec;
    std::deque<int> numbers_deq;
    int i = 1;
    for (; argv[i]; i++)
    {
        numbers_vec.push_back(std::stoi(argv[i]));
        numbers_deq.push_back(std::stoi(argv[i]));
    }
    clock_t startTime_vec = clock();
    mergeInsertionSort_vector(numbers_vec, i / 2);
    clock_t endTime_vec = clock();
    double duration_vec = static_cast<double>(endTime_vec - startTime_vec) / (double)CLOCKS_PER_SEC;
    clock_t startTime_deq = clock();
    mergeInsertionSort_deque(numbers_deq, i / 2);
    clock_t endTime_deq = clock();
    double duration_deq = static_cast<double>(endTime_deq - startTime_deq) / (double)CLOCKS_PER_SEC;
    for (std::vector<int>::const_iterator it = numbers_vec.begin(); it != numbers_vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    for (std::deque<int>::const_iterator it = numbers_deq.begin(); it != numbers_deq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::fixed << duration_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << std::fixed << duration_deq << " us" << std::endl;
}