#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();

	std::cout << "cat idea 50 : " << i->getIdea(50) << std::endl;
	i->makeSound();
	std::cout << "dog idea 99 : " << j->getIdea(99) << std::endl;
	j->makeSound();

	i->setIdea(50, "sleep.");
	j->setIdea(99, "sleep.");

	std::cout << "cat idea 50 : " << i->getIdea(50) << std::endl;
	std::cout << "dog idea 99 : " << j->getIdea(99) << std::endl;

	Dog test;
	test.makeSound();
	test.setIdea(1, "sleep.");

	Dog copy = test;
	std::cout << "test idea 1: " << test.getIdea(1) << std::endl;
	std::cout << "copy idea 1: " << copy.getIdea(1) << std::endl;

    delete meta;
    delete j;
    delete i;

    return 0;
}

