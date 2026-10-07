#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data		original;
	Data		*ptr;
	uintptr_t	raw;
	Data		*result;

	// Fill the object with some content so it is a real, usable object.
	original.id = 42;
	original.name = "forty-two";
	original.value = 4.2;

	ptr = &original;

	raw = Serializer::serialize(ptr);
	result = Serializer::deserialize(raw);

	std::cout << "Original pointer   : " << ptr << std::endl;
	std::cout << "Serialized value   : " << raw << std::endl;
	std::cout << "Deserialized pointer: " << result << std::endl;
	std::cout << std::endl;

	if (result == ptr)
		std::cout << "OK: deserialize(serialize(ptr)) == ptr" << std::endl;
	else
		std::cout << "KO: pointers differ" << std::endl;

	// Prove the recovered pointer really points to the same object.
	std::cout << std::endl;
	std::cout << "Through recovered pointer -> id: " << result->id
			  << ", name: " << result->name
			  << ", value: " << result->value << std::endl;

	return 0;
}
