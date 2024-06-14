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

template<typename T>
void join(T &pairs, T &a, T &b)
{
	pairs.clear();

	size_t i = 0, j = 0;
	while (i < a.size() && j < a.size())
	{
		if (a[i].second <= b[j].second)
			pairs.push_back(a[i++]);
		else
			pairs.push_back(b[j++]);
	}

	while (i < a.size())
		pairs.push_back(a[i++]);
	while (j < b.size())
		pairs.push_back(b[j++]);
}

template<typename T>
void merge(T &pairs) 
{
	if (pairs.size() > 1)
	{
		T a(pairs.begin(), pairs.begin() + pairs.size() / 2);
		merge(a);
		T b(pairs.begin() + pairs.size() / 2, pairs.end());
		merge(b);
		join(pairs, a, b);
	}
}

#endif
