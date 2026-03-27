#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "WrongDog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
	std::cout << "//WrongAnimals//" << std::endl;
	const WrongAnimal* Wrong_meta = new WrongAnimal();
	const WrongAnimal* Wrong_i = new WrongCat();
	const WrongAnimal* Wrong_j = new WrongDog();
	std::cout << Wrong_j->getType() << " " << std::endl;
	std::cout << Wrong_i->getType() << " " << std::endl;
	Wrong_i->makeSound(); //will output the wrong sound!
	Wrong_j->makeSound();
	Wrong_meta->makeSound();
	delete Wrong_meta;
	delete Wrong_i;
	delete Wrong_j;

	std::cout << "//Animals//" << std::endl;
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	
	std::cout << "// Copy constructor //" << std::endl;
    Cat a;
    Cat b(a);   // Copy constructor

    std::cout << a.getType() << std::endl;
    std::cout << b.getType() << std::endl;
    a.makeSound();
    b.makeSound();

    std::cout << "// Assignment operator //" << std::endl;
    Dog c;
    Dog d;
    d = c;      // Copy assignment operator

    std::cout << c.getType() << std::endl;
    std::cout << d.getType() << std::endl;
    c.makeSound();
    d.makeSound();
	return (0);
}
