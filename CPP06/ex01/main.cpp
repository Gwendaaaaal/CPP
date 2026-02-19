#include "Serializer.hpp"

int main(void)
{
	Data* data_ptr = new Data;
	data_ptr->n = 10;
	data_ptr->c = 'a';
	std::cout << "n : " << data_ptr->n << ", c : " << data_ptr->c << std::endl;
	uintptr_t uintptr = Serializer::serialize(data_ptr);
	Data* new_data_ptr = Serializer::deserialize(uintptr);
	std::cout << "n : " << new_data_ptr->n << ", c : " << new_data_ptr->c << std::endl;

	std::cout << "data_ptr : " << data_ptr << std::endl;
	std::cout << "new_data_ptr : " << new_data_ptr << std::endl;
	std::cout << "data_ptr == new_data_ptr : " << (data_ptr == new_data_ptr) << std::endl;

	delete data_ptr;

	return (0);
}
