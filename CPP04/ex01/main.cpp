#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << i->getType() << std::endl;
    std::cout << j->getType() << std::endl;
    i->makeSound(); 
    j->makeSound();
    meta->makeSound();

	std::cout << "cat idea 50 : " << i->getIdea(50) << std::endl;
	std::cout << "dog idea 99 : " << j->getIdea(99) << std::endl;

    delete meta;
    delete j;
    delete i;

    return 0;
}

