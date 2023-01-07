#include "WrongDog.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	int		i = -1;
	int		num = 10;
	const AAnimal	*AAnimal[num];

	//creating AAnimals
	std::cout << "\n-------Creating array of " << num << " AAnimals-------\n" << std::endl;
	while (++i < (num / 2))
		AAnimal[i] = new Dog();
	i--;
	while (++i < num)
		AAnimal[i] = new Cat();

	//testing AAnimals sound
	std::cout << "\n-------Testing AAnimals sound-------\n" << std::endl;
	AAnimal[0]->makeSound();
	AAnimal[num / 2]->makeSound();
	AAnimal[num - 1]->makeSound();

	//testing copy
	std::cout << "\n-------Testing deep copy. creating a dog with brain and a copy to the dog-------\n" << std::endl;
	Dog	*dog = new Dog();
	dog->setIdea("Lets go for a ride", 0);
	dog->setIdea("You wanna ice cream?", 99);
	Dog	*copy_dog = new Dog(*dog);
	std::cout << "\n-------Deleting original dog. accessing ideas of the copy should not be segfault-------\n" << std::endl;
	delete dog;
	std::cout << "\n-------original dog is deleted, printing ideas:-------\n" << std::endl;
	std::cout << "idea 0 : " << copy_dog->getIdea(0) << std::endl;
	std::cout << "idea 99 : " << copy_dog->getIdea(99) << std::endl;
	delete copy_dog;

	std::cout << "\n-------Deleting AAnimal array-------\n" << std::endl;
	i = -1;
	while (++i < num)
		delete AAnimal[i];
	
	std::cout << "\n-------------------- leaks check --------------------\n" << std::endl;

	system("leaks worldOnFire");

	return 0;
}
