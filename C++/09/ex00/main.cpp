#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int	error_ret(std::string str){
	std::cout << str << std::endl;
	return (1);
}

int	main(int argc, char **argv){
	std::string		line;
	std::ifstream	input;
	std::ifstream	data;
	myMap			data_map;

	std::cout.precision(7);
	if (argc != 2)
		return (error_ret( "Error: the program must take one valid database file \
as an argument."));
	input.open(argv[1], std::ifstream::in);
	data.open("./data.csv", std::ifstream::in);
	if (!data)
		return (error_ret("Error: data file can't be opened."));
	if (!input)
		return (error_ret("Error: input file can't be opened."));
	std::getline(data, line);
	while (std::getline(data, line))
		data_map[line.substr(0, 10)] = atof(line.substr(11).c_str());

	BitcoinExchange	btc(&input, &data_map);
	btc.converter();

	input.close();
	data.close();
	
	return 0;
}
