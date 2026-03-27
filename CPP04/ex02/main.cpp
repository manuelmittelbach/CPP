#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "========== BASIC POLYMORPHIC DELETE ==========" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;

		j->makeSound();
		i->makeSound();

		delete j;
		delete i;
	}

	std::cout << "\n========== DOG COPY CONSTRUCTOR ==========" << std::endl;
	{
		Dog original;
		original.setIdea(0, "chase the mailman");
		original.setIdea(1, "eat a bone");

		Dog copy(original);

		std::cout << "original idea[0]: " << original.getIdea(0) << std::endl;
		std::cout << "copy     idea[0]: " << copy.getIdea(0) << std::endl;

		copy.setIdea(0, "sleep on the sofa");

		std::cout << "After modifying copy:" << std::endl;
		std::cout << "original idea[0]: " << original.getIdea(0) << std::endl;
		std::cout << "copy     idea[0]: " << copy.getIdea(0) << std::endl;
	}

	std::cout << "\n========== CAT COPY ASSIGNMENT ==========" << std::endl;
	{
		Cat first;
		Cat second;

		first.setIdea(0, "climb a tree");
		first.setIdea(1, "catch a mouse");

		second.setIdea(0, "do nothing");

		second = first;

		std::cout << "first  idea[0]: " << first.getIdea(0) << std::endl;
		std::cout << "second idea[0]: " << second.getIdea(0) << std::endl;

		second.setIdea(0, "sleep on the keyboard");

		std::cout << "After modifying second:" << std::endl;
		std::cout << "first  idea[0]: " << first.getIdea(0) << std::endl;
		std::cout << "second idea[0]: " << second.getIdea(0) << std::endl;
	}
	return 0;
}
