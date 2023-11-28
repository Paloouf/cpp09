/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:56:58 by ltressen          #+#    #+#             */
/*   Updated: 2023/11/28 15:03:38 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cctype>

class RPN{
	public:
		RPN();
		RPN(std::string input);
		~RPN();
		RPN(const RPN& ref);
		RPN& operator=(const RPN& ref);

		void	doOp();
		void	printStack();
	private:
		std::stack<int> _stack;
		std::stack<std::string> _ope;
		
};