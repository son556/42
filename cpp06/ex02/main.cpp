#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base* b = generator();
	Base& c = *(generator());

	identify(b);
	identify(c);
	system("leaks identify | grep total");
}