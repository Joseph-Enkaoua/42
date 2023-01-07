#include <iostream>
#include <sys/time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void) {
	struct timeval	t;
	A	*a = new A();
	B	*b = new B();
	C	*c = new C();
	gettimeofday(&t, NULL);
	switch (t.tv_usec % 3) {
		case 0:
			delete b;
			delete c;
			return reinterpret_cast<Base*>(a);
		case 1:
			delete a;
			delete c;
			return reinterpret_cast<Base*>(b);
	}
	delete a;
	delete b;
	return reinterpret_cast<Base*>(c);
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "class type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "class type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "class type: C" << std::endl;
	else
		std::cout << "class is not A, B or C type!" << std::endl;
}

void	identify(Base& p) {
	Base	base;
	try {
		base = dynamic_cast<A&>(p);
		std::cout << "class type: A" << std::endl;
	} catch(const std::exception& e) {}
	try {
		base = dynamic_cast<B&>(p);
		std::cout << "class type: B" << std::endl;
	} catch(const std::exception& e) {}
	try {
		base = dynamic_cast<C&>(p);
		std::cout << "class type: C" << std::endl;
	} catch(const std::exception& e) {}
}

int	main() {
	//generating random drived class
	Base*	pointer_a = generate();
	//and one more
	Base*	pointer_b = generate();
	//checking their types by pointer
	identify(pointer_a);
	identify(pointer_b);
	//checking their types by reference
	identify(*pointer_a);
	identify(*pointer_b);
	return 0;
}