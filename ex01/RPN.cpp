/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:01:33 by ltressen          #+#    #+#             */
/*   Updated: 2023/11/28 15:11:22 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(std::string input){
	std::stringstream s(input);
	std::string insert;
	if (input.size() < 3)
	{
		std::cout << "Expression not long enough\n";
		return ;
	}
	while (getline(s, insert, ' ')){
		if (isdigit(insert.c_str()[0]) != 0){
			_stack.push(insert.c_str()[0] - '0');}
		else if (!insert.compare("-") || !insert.compare("+") || !insert.compare("/") || !insert.compare("*")){
			_ope.push(insert);
			doOp();
		}
		else
		{
			std::cout << "Wrong format\n";
			return;
		}
	}
	if (_ope.empty() && _stack.size() == 1)
		std::cout << _stack.top() << std::endl;	
	else
		std::cout << "Missing operands or numbers\n";
}

RPN::~RPN(){}

RPN::RPN(const RPN& ref){
	*this=ref;
}

RPN& RPN::operator=(const RPN& ref){
	(void)ref;
	return *this;
}

void	RPN::printStack(){
	while (!_stack.empty()){
		std::cout << "int: " <<  _stack.top() << std::endl;
		_stack.pop();
	}
	while (!_ope.empty()){
		std::cout << "ope: " << _ope.top() << std::endl;
		_ope.pop();
	}
}

void	RPN::doOp(){
	int res;
	while (!_ope.empty()){	
		if (!_ope.top().compare("+"))
		{
			res = _stack.top();
			_stack.pop();
			_stack.top() = res + _stack.top();
			_ope.pop();
		}
		else if (!_ope.top().compare("-")){
			res = _stack.top();
			_stack.pop();
			_stack.top() = _stack.top() - res ;
			_ope.pop();
		}
		else if (!_ope.top().compare("/")){
			res = _stack.top();
			_stack.pop();
			_stack.top() = _stack.top() / res;
			_ope.pop();
		}
		else if (!_ope.top().compare("*")){
			res = _stack.top();
			_stack.pop();
			_stack.top() = res * _stack.top();
			_ope.pop();
		}
	}
}

