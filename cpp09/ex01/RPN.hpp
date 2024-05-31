#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <queue>

class RPN
{

private:
	std::queue<char> parse(const std::string &input);
	int execute(std::queue<char> &queue, int result);

public:
	RPN();
	RPN(const RPN &other);
	~RPN();

	int process(const std::string &input);

	RPN &operator=(const RPN &other);

	class InvalidInputException: std::exception
	{ };

};

#endif
