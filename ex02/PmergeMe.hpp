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
#include <list>
#include <cstdlib>
#include <cmath>

class PmergeMe{
	public:
		PmergeMe();
		PmergeMe(char** input);
		~PmergeMe();
		PmergeMe(const PmergeMe& ref);
		PmergeMe& operator=(const PmergeMe& ref);
		void	parsing();
		void	printCont();
		
	private:
		std::vector<int> _vec;
		std::list<int> _list;
		char** _input;
};