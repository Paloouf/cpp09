/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:22:56 by ltressen          #+#    #+#             */
/*   Updated: 2023/11/28 16:02:27 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(char** input) :_input(input){
	parsing();
	sorting();
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& ref){
	*this = ref;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& ref){
	(void)ref;
	return *this;
}

void	PmergeMe::insertSortV(std::vector<int>& vec){
	int n = vec.size();
	for(int i = 1; i < n; ++i){
		int val = vec[i];
		int j = i - 1;
		while (j >= 0 && val < vec[j]){
			vec[j + 1] = vec[j];
			--j;
		}
		vec[j + 1] = val;
	}
}

void	PmergeMe::mergeV(std::vector<int>& vec, std::vector<int>& left, std::vector<int>& right){
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;

	while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            vec[k] = left[i];
            ++i;
		} 
		else {
            vec[k] = right[j];
            ++j;
        }
        ++k;
    }
    while (i < left.size()) {
        vec[k] = left[i];
        ++i;
        ++k;
    }
    while (j < right.size()) {
        vec[k] = right[j];
        ++j;
        ++k;
    }
}

void	PmergeMe::sortVec(std::vector<int>& vec){
	if (vec.size() <= 10)
		insertSortV(vec);
	else
	{
		int mid = vec.size() / 2;
		std::vector<int> left(vec.begin(), vec.begin() + mid);
		std::vector<int> right(vec.begin() + mid, vec.end());

		sortVec(left);
		sortVec(right);

		mergeV(vec, left, right);
	}
}
void	PmergeMe::insertSortD(std::deque<int>& deque){
	for (std::size_t i = 1; i < deque.size(); ++i) {
        int val = deque[i];
        std::size_t j = i;
        while (j > 0 && val < deque[j - 1]) {
            deque[j] = deque[j - 1];
            --j;
        }
        deque[j] = val;
    }
}
void	PmergeMe::mergeD(std::deque<int>& deque, std::deque<int>& left, std::deque<int>& right){
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;

	while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            deque[k] = left[i];
            ++i;
		} 
		else {
            deque[k] = right[j];
            ++j;
        }
        ++k;
    }
    while (i < left.size()) {
        deque[k] = left[i];
        ++i;
        ++k;
    }
    while (j < right.size()) {
        deque[k] = right[j];
        ++j;
        ++k;
    }
}

void	PmergeMe::sortDeq(std::deque<int>& deque){
	if (deque.size() <= 10) {
        insertSortD(deque);
    } else {
        std::size_t mid = deque.size() / 2;
        std::deque<int> left(deque.begin(), deque.begin() + mid);
        std::deque<int> right(deque.begin() + mid, deque.end());

        sortDeq(left);
        sortDeq(right);

        mergeD(deque, left, right);
    }
}

void	PmergeMe::sorting(){
	clock_t start, finish;
	double	timeVec, timeList;

	start = clock();
	sortVec(_vec);
	finish = clock();
	timeVec = (double)((finish - start)) / CLOCKS_PER_SEC;
	
	start = clock();
	sortDeq(_deque);
	finish = clock();
	timeList = (double)((finish - start)) / CLOCKS_PER_SEC;

	printCont();
	printContAfter();

	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector is: " << std::fixed << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque is: " << std::fixed << timeList << " us" << std::endl;
	return ;
}

void	PmergeMe::printCont(){
	static int i = 0;
	std::vector<int>::iterator itv = _vec.begin();
	if (i == 0){
		std::cout << "Before Vec: ";
		while(itv != _vec.end()){
			std::cout << *itv++ << " "; 
		}
		std::cout << std::endl;}
	else{
		std::cout << "After Vec: ";
		while(itv != _vec.end()){
			std::cout << *itv++ << " "; 
		}
		std::cout << std::endl;}
	i++;
}

void	PmergeMe::printContAfter(){
	static int i = 0;
	std::deque<int>::iterator itv = _deque.begin();
	
	if (i == 0){
		std::cout << "Before Deq: ";
		while(itv != _deque.end()){
			std::cout << *itv++ << " "; 
		}
		std::cout << std::endl;}
	else
	{
		std::cout << "After Deq: ";
		while(itv != _deque.end()){
			std::cout << *itv++ << " "; 
		}
		std::cout << std::endl;
	}
	i++;
}


void PmergeMe::parsing()
{
	int	i, j;

	i = 1;
	while (_input[i])
	{
		j = 0;
		while (_input[i][j])
		{
			if (!isdigit(_input[i][j])){
				std::cout << "Not a number\n";
				exit(-1);}
			j++;
		}
		_vec.push_back(atoi(_input[i]));
		_deque.push_back(atoi(_input[i]));
		i++;
	}
	printCont();
	printContAfter();
}



