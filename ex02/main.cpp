/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:15:54 by ltressen          #+#    #+#             */
/*   Updated: 2023/11/28 15:21:32 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int c, char **v){
	if (c > 1)
		PmergeMe sort(v);
	else
		std::cout << "Usage: ./PmergeMe -arguments\n";
	return 0;
}