#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>

class PmergeMe
{

private:
	int parse(const std::string &param);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &other);

	void sort(std::vector<int> v);

	class InvalidInputException: std::exception
	{ };

};

#endif
