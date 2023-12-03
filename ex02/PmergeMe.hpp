/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:21:38 by ltressen          #+#    #+#             */
/*   Updated: 2023/11/28 15:57:52 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cmath>
#include <algorithm>

class PmergeMe{
	public:
		PmergeMe();
		PmergeMe(char** input);
		~PmergeMe();
		PmergeMe(const PmergeMe& ref);
		PmergeMe& operator=(const PmergeMe& ref);
		void	parsing();
		void	printCont();
		void	printContAfter();
		void	sorting();

		//Vector functions
		void	insertSortV(std::vector<int>& vec);
		void	mergeV(std::vector<int>& vec, std::vector<int>& left, std::vector<int>& right);
		void	sortVec(std::vector<int>& vec);

		//deque functions
		void	insertSortD(std::deque<int>& deque);
		void	mergeD(std::deque<int>& deque, std::deque<int>& left, std::deque<int>& right);
		void	sortDeq(std::deque<int>& deque);

		
	private:
		std::vector<int> _vec;
		std::deque<int> _deque;
		char** _input;
};