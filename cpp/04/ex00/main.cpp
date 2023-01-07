#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
std::cout << "\n\n<<-- Zoo of Animals: -->>\n\n";
	{
		std::cout << "\n\n-- Creating Animals: --\n\n";
		Animal *meta = new Animal();
		Animal *cat = new Cat();
		Animal *dog = new Dog();

		Animal	catCopy = *cat;
		Dog 	dogCopy(*dog);

		std::cout << "\n\n-- Printing Types of Animals: --\n\n";
		std::cout << "Type: " << meta->getType() << std::endl;
		std::cout << "Type: " << cat->getType() << std::endl;
		std::cout << "Type: " << catCopy.getType() << std::endl;
		std::cout << "Type: " << dog->getType() << std::endl;
		std::cout << "Type: " << dogCopy.getType() << std::endl;

		std::cout << "\n\n-- Make some Noise!!! --\n\n";
		meta->makeSound();
		cat->makeSound();
		catCopy.makeSound();
		dog->makeSound();
		dogCopy.makeSound();

		std::cout << "\n\n-- Bye Bye Animals --\n\n";
        delete meta;
        delete dog;
        delete cat;
	}
	std::cout << "\n\n<<-- Zoo of WrongAnimals: -->>\n\n";
	{
		std::cout << "\n\n-- Creating Animals: --\n\n";
		const WrongAnimal *wrong_meta = new WrongAnimal();
		const WrongAnimal *wrong_dog = new WrongDog();
		const WrongAnimal *wrong_cat = new WrongCat();
		const WrongAnimal wrong_dogCopy(*wrong_dog);

		std::cout << "\n\n-- Printing Types of Animals: --\n\n";
        std::cout << "Type: " << wrong_meta->getType() << std::endl;
		std::cout << "Type: " << wrong_cat->getType() << std::endl;
		std::cout << "Type: " << wrong_dog->getType() << std::endl;
		std::cout << "Type: " << wrong_dogCopy.getType() << std::endl;

		std::cout << "\n\n-- Make some Noise!!! --\n\n";
		wrong_meta->makeSound();
		wrong_cat->makeSound();
		wrong_dog->makeSound();
		wrong_dogCopy.makeSound();

		std::cout << "\n\n-- Bye Bye Animals --\n\n";
        delete wrong_meta;
        delete wrong_dog;
        delete wrong_cat;
	}
}
