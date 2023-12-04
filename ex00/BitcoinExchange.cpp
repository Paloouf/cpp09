/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:26:10 by ltressen          #+#    #+#             */
/*   Updated: 2023/12/04 16:15:08 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(char* filename) : _filename(filename){
	getData();
	checkFormat();
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref){
	*this = ref;	
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref){
	(void)ref;
	return *this;
}

void	BitcoinExchange::fillMap(std::string line){
	std::stringstream   sLine(line);
	std::string         value, date;
	
	std::getline(sLine, date, ',');
	std::getline(sLine, value);
	_dataRates[date] = atof(value.c_str());
	//std::cout << date << ": " << _dataRates[date] << std::endl;
}


void	BitcoinExchange::getData(){
	std::ifstream data("data.csv");
	std::string line;
	
	if (data.is_open())
		while (std::getline(data, line))
			fillMap(line);
	else{
		std::cout << "Can't open file\n";
		return ;}
	data.close();
}

std::string	BitcoinExchange::findNextDate(std::string date)
{
	std::stringstream   sDate(date);
	std::string         year, month, day, result;

	std::getline(sDate, year, '-');
	std::getline(sDate, month, '-');
	std::getline(sDate, day);
	int	y = atoi(year.c_str());
	int	m = atoi(month.c_str());
	int	d = atoi(day.c_str());
	if (d > 1)
		d--;
	else if (m > 1)
	{
		d = 31;
		m--;
	}
	else if (y > 2008)
	{
		d = 31;
		m = 12;
		y--;
	}
	std::stringstream res;
	res << y << '-' << std::setw(2) << std::setfill('0') << m << '-' << std::setw(2) << std::setfill('0') << d;
	result = res.str();
	return (result);
}

void	BitcoinExchange::findRate(std::string date, float value){
	if (_dataRates.find(date) != _dataRates.end())
	{
		float res = value * _dataRates[date];
		std::cout << date << " => "<< value << " = " << res << std::endl;
		return;
	}
	else
	{
		date = findNextDate(date);
		findRate(date, value);
	}
}

void	BitcoinExchange::checkDates(std::string check){
	std::stringstream sCheck(check);
	std::string date, delim, value;

	sCheck >> date;
	sCheck >> delim;
	sCheck >> value;
	
	std::stringstream	sDate(date);
	std::string year, month, day;
	
	if (date.size() != 10 || date[4] != '-' || date[7] != '-'){
		std::cout << "Wrong date format\n";
		return;}
		
	std::getline(sDate, year, '-');
	std::getline(sDate, month, '-');
	std::getline(sDate, day);
	if (atoi(year.c_str()) > 2022 || atoi(year.c_str()) < 2009){
		std::cout << "Wrong year format\n";
		return ;}
	else if (atoi(month.c_str()) > 12 || atoi(month.c_str()) < 1){
		std::cout << "Wrong month format\n";
		return;}
	else if (atoi(day.c_str()) > 31 || atoi(day.c_str()) < 1){
		std::cout << "Wrong day format\n";
		return;}
	else if (check.find(" | ") != 10){
		std::cout << "Wrong delimiter format\n";
		return;}
		
	float valueCheck = atof(value.c_str());
	if (value.find("-") == 0){
		std::cout << "Invalid negative value format\n";
		return ;}
	
	else if (valueCheck < 0 || valueCheck > 1000){
		std::cout << "Invalid value format\n";
		return;}
	for (unsigned long i = 0; i < value.size(); i++){
		if (!(isdigit(value[i]) || value[i] == '.')){
			std::cout << "Invalid value format\n";
			return;}
	}	
	findRate(date, valueCheck);
}

void BitcoinExchange::checkFormat(){
	std::ifstream file(this->_filename.c_str());
	std::string check;

	if (file.is_open())
	{
		std::getline(file, check);
		while (std::getline(file, check))
			checkDates(check);
	}
	else{
		std::cout << "Can't open file\n";
		return ;}
	file.close();
}