/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:24:55 by ltressen          #+#    #+#             */
/*   Updated: 2023/11/27 14:33:17 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int c, char** v){
	if (c == 2)
	{
		BitcoinExchange Rates(v[1]);
	}
	return 0;
}