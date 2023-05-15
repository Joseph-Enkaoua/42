#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv) {
	int	i = 0;
	while (argv[++i] && is_digit(argv[i])) {
		_deq.push_back(atoi(argv[i]));
        _vec.push_back(atoi(argv[i]));
	}
	sort_print();
}

PmergeMe::PmergeMe(const PmergeMe & rhs) {
	*this = rhs;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe & rhs) {
	std::copy(rhs._vec.begin(), rhs._vec.end(), _vec.begin());
	std::copy(rhs._deq.begin(), rhs._deq.end(), _deq.begin());
	sort_print();
	return (*this);
}

bool	PmergeMe::is_digit(const std::string str) {
	for (int i = 0; i < (int)str.size(); i++)
		if (!isdigit(str[i])) {
			std::cerr << "Error\n";
			exit(0);
		}
	return true;
}

void	PmergeMe::print_sample(std:: string str) {
	std::deque<int>::iterator it = _deq.begin();
	std::cout << str << ": ";
	while (it != _deq.end() && std::distance(_deq.begin(), it) < 4)
		std::cout << *it++ << " ";
	if (_deq.size() == 5)
		std::cout << *it;
	else if (_deq.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
}

void	PmergeMe::sort_print() {
	clock_t	start;
	clock_t	end;
	double	elapsed;

	print_sample("Before sort");

	start = clock();
	merge_sort(_deq);
	_deq.assign(_deq.begin(), std::unique(_deq.begin(), _deq.end()));
	end = clock();
	elapsed = double(end - start) / CLOCKS_PER_SEC;
	print_sample("After sort");
	std::cout << "Time to process with std::deque: " << elapsed * 1000000 << " microseconds\n";

	start = clock();
	merge_sort(_vec);
	_vec.assign(_vec.begin(), std::unique(_vec.begin(), _vec.end()));
	end = clock();
	elapsed = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process with std::vector: " << elapsed * 1000000 << " microseconds\n";
}
