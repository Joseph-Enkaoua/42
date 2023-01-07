#include "Array.hpp"

#define MAX_VAL 20

int main(void) {

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "Test Array Generation" << std::endl
                << "array[] numbers: ";
    printArray(numbers, MAX_VAL); 
    std::cout << std::endl
                << "array[] mirror: ";
    printTypeArray(mirror, MAX_VAL);
    std::cout << std::endl << std::endl; 

    // testing deep copy
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "Test Deep Copy" << std::endl
                    << "array[] test: ";
        printArray(test, MAX_VAL);
        std::cout << std::endl << std::endl; 
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    std::cout << "Trying to access array[-2]. Should return an exception." << std::endl; 
    try {
        numbers[-2] = 0;
    } catch(std::exception const& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Trying to access array[MAX_VALUE]. Should return an exception." << std::endl; 
    try {
        numbers[MAX_VAL] = 0;
    } catch(std::exception const& e) {
        std::cerr << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }

    delete[] mirror;

    return 0;
}