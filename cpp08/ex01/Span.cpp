#include "Span.hpp"

Span::Span()
{
}

Span::Span(const Span& ref)
{
	*this = ref;
}

Span& Span::operator=(const Span& ref)
{
	this->vec = ref.vec;
	this->N = ref.N;
	return *this;
}

Span::Span(unsigned int num)
{
	this->N = num;
}

Span::~Span()
{
}

void Span::addNumber(const int n)
{
	if (this->vec.size() == this->N)
		throw "span full!!";
	this->vec.push_back(n);
}

void Span::addNumbers(const std::vector<int> v)
{
	if (v.size() > (N - vec.size()))
		throw "too many factors!!";
	for (size_t i = 0; i < v.size(); i++)
		vec.push_back(v[i]);
}

unsigned int Span::shortestSpan() const
{
	unsigned int dis = 4294967295;

	if (vec.size() < 2)
		throw "span too short!!";
	std::vector<int> v = vec;
	sort(v.begin(), v.end());
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		if ((unsigned long)abs(v[i] - v[i + 1]) < dis)
			dis = (unsigned int)abs(v[i] - v[i + 1]);
	}
	return dis;
}

unsigned int Span::longestSpan() const
{
	unsigned int dis = 0;

	if (vec.size() < 2)
		throw "span too short!!!";
	std::vector<int> v = vec;
	sort(v.begin(), v.end());
	dis = (unsigned int)abs(v[0] - v[vec.size() - 1]);
	return dis;
}