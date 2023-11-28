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
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& ref){
	*this = ref;
}

void	PmergeMe::sorting(){
	
}

void	PmergeMe::printCont(){
	std::vector<int>::iterator itv = _vec.begin();
	
	std::cout << "Before: ";
	while(itv != _vec.end()){
		std::cout << *itv++ << " "; 
	}
	sorting();
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
			if (isdigit(_input[i][j]) == 0){
				std::cout << "Not a number\n";
				exit(-1);}
			j++;
		}
		_vec.push_back(atoi(_input[i]));
		_list.push_back(atoi(_input[i]));
		i++;
	}
	printCont();
}


PmergeMe& PmergeMe::operator=(const PmergeMe& ref){
	(void)ref;
	return *this;
}

