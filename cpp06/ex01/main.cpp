#include "header.hpp"
#include <iostream>

uintptr_t serialize(Data *data)
{
	return reinterpret_cast<uintptr_t>(data);
}

Data *deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

static void printData(Data &data)
{
	std::cout << "name: " << data.name << std::endl;
	std::cout << "value: " << data.value << std::endl;
}

int main()
{
	Data data;

	data.name = "bob";
	data.value = 5;

	printData(data);

	uintptr_t raw = serialize(&data);
	Data *copy = deserialize(raw);

	printData(*copy);

	return 0;
}

