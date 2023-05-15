#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	_input = NULL;
}

BitcoinExchange::BitcoinExchange(std::ifstream *input, myMap *data_map){
	_input = input;
	_data_map = data_map;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &btc){
	*this = btc;
}

BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange & BitcoinExchange::operator = (const BitcoinExchange &btc){
	this->_input = btc._input;
	this->_data_map = btc._data_map;
	return (*this);
}

int	BitcoinExchange::err_print(std::string str){
	std::cout << str << std::endl;
	return 0;
}

int BitcoinExchange::is_valid_date(const std::string& date_str) {
	struct tm	date;
	time_t		t;
	date_t		d;

	d.year = std::atoi(date_str.substr(0, 4).c_str()) - 1900;
	d.month = std::atoi(date_str.substr(5, 2).c_str()) - 1;
	d.day = std::atoi(date_str.substr(8, 2).c_str());
	
	std::memset(&date, 0, sizeof(date));
	date.tm_year = d.year;
	date.tm_mon = d.month;
	date.tm_mday =d.day;
	t = std::mktime(&date);

    if (t == -1 || date.tm_year != d.year || date.tm_mon != d.month || date.tm_mday != d.day)
        return 0;

    return 1;
}

int BitcoinExchange::check_line(const std::string line){
	_date = line.substr(0, 10);
	if (line.length() < 14 || line[4] != '-' || line[7] != '-' || !is_valid_date(_date))
		return (err_print("Error: bad input => " + line));
	_value = std::atof(line.substr(13).c_str());
	if (_value < 0 || !_value)
		return (err_print("Error: value must be a positive int."));
	if (_value > 1000)
		return (err_print("Error: value can't be bigger than 1000."));
	return (1);
}

int BitcoinExchange::converter(){
	std::string		line;
	myMap::iterator	it;

	std::getline(*_input, line, '\n');
	while (std::getline(*_input, line, '\n')){
		if (!check_line(line))
			continue;
		it = _data_map->upper_bound(line.substr(0, 10));
		--it;
		std::cout << _date << " => " << _value << " = " << it->second * _value << std::endl;
	}
	return 0;
}