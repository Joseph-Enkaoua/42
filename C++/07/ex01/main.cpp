#include "iter.hpp"

int	main(void)
{
	int         arr1[] = {1, 2, 3, 4, 5};
	float       arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "int array: ";
    printArray(arr1, 5);
    std::cout << std::endl;
	iter(arr1, 5, multiplyByFive<int>);
	std::cout << std::endl;
    std::cout << "float array: ";
    printArray(arr2, 5);
    std::cout << std::endl;
	iter(arr2, 5, multiplyByFive<float>);
	std::cout << std::endl;

    char        arr3[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	std::string arr4[] = {"hi", "this", "is", "me"};

    std::cout << "char array: ";
    printArray(arr3, 6);
    std::cout << std::endl;
	iter(arr3, 6, toUpperChar);
	std::cout << std::endl;
    std::cout << "string array: ";
    printArray(arr4, 4);
    std::cout << std::endl;
	iter(arr4, 4, toUpperString);
	std::cout << std::endl;
	std::cout << std::endl;
	return (0);
}

char    toUpperChar(char c)
{
    char    upperC;

    upperC = std::toupper(c);
    std::cout << "toUpperChar:" << upperC << std::endl;
    return (upperC);
}

std::string    toUpperString(std::string s)
{
    for (size_t i = 0; i < s.length(); i++)
        s[i] = std::toupper(s[i]);
    std::cout << "toUpperString:" << s << std::endl;
    return (s);
}
