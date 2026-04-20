#include <iostream>
#include "Serializer.hpp"

int main(void)
{

	Data *data = new Data;
	data->str = "Peter";
	data->n = 42;

	uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);

	std::cout<<serialized->str<<std::endl;
	std::cout<<serialized->n<<std::endl;

	delete data;
	return (0);
}