#include "easyfind.hpp"

int main(void)
{
	int to_find = 88;
	int content[] = {1324, 4068, 20349, 203847, to_find, 1, 23408234, 23482, 23948};
	std::vector<int> vec(content, content + sizeof(content) / sizeof(int));
	try
	{
		std::vector<int>::const_iterator it = easyfind(vec, to_find);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	to_find = 99;
	try
	{
		std::vector<int>::const_iterator it = easyfind(vec, to_find);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
    return 0;
}
