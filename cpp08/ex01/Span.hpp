#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
class Span
{
	private:
		std::vector<int> vec;
		unsigned int N;
	public:
		Span();
		Span(const Span& ref);
		Span& operator=(const Span& ref);
		Span(unsigned int num);
		~Span();
		void addNumber(const int n);
		void addNumbers(const std::vector<int> v);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};
#endif