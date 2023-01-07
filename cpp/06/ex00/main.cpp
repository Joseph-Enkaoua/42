#include "Converter.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: invalid input\n";
		return 0;
	}
	try
	{
		Converter	value(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}