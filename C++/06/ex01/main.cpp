#include <iostream>

struct Data
{
	char	c;
	int		i;
	void	*v;
};

uintptr_t	serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main() {
	Data	*ret;
	Data	data;
	Data*	data_p = &data;

	ret = deserialize(serialize(data_p));
	std::cout << "original data pointer address: " << data_p << std::endl
			  << "returned data pointer address: " << ret << std::endl;
	return 0;
}