/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:25:13 by ltressen          #+#    #+#             */
/*   Updated: 2023/11/27 15:26:40 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>


class BitcoinExchange
{
public:
	
	BitcoinExchange(char* filename);
	~BitcoinExchange();

	void	checkFormat();
	void	checkDates(std::string check);
	void	findRate(std::string date, float value);
	std::string	findNextDate(std::string date);
	
	void	getData();
	void	fillMap(std::string line);


	class WrongFormat : public std::exception{
		const char* what() const throw(){
			return ("Wrong Format\n");
		}
	};

	class FileException : public std::exception{
		const char* what() const throw(){
			return ("Couldn't open file\n");
		}
	};
private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& ref);
	BitcoinExchange &operator=(const BitcoinExchange& ref);
	std::map<std::string, float> _dataRates;
	std::string _filename;
};
