#include "RPN.hpp"
#include <iostream>

RPN::RPN()
{ }

RPN::RPN(const RPN &other)
{
	(void) other;
}

RPN::~RPN()
{ }

static bool isop(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

static char frontPop(std::queue<char> &queue)
{
	char c = queue.front();
	queue.pop();
	return c;
}



std::queue<char> RPN::parse(const std::string &input)
{
	std::queue<char> queue;

	for (size_t i = 0; i < input.size(); i++)
	{
		if (isspace(input[i]))
			continue;
		if (isdigit(input[i]) || isop(input[i]))
		{
			queue.push(input[i]);
			if (input[i + 1] != 0 && input[i + 1] != ' ')
				throw InvalidInputException();
			continue;
		}
		throw InvalidInputException();
	}

	return queue;
}

int RPN::execute(std::queue<char> &queue, int result)
{
	char c = frontPop(queue);
	if (!isdigit(c) || queue.empty())
		throw InvalidInputException();

	int i = c - '0';
	if (isdigit(queue.front()))
		i = execute(queue, i);
	
	char op = frontPop(queue);
	switch (op)
	{
		case '+':
			result += i;
			break;
		case '-':
			result -= i;
			break;
		case '*':
			result *= i;
			break;
		case '/':
			if (i == 0)
				throw InvalidInputException();
			result /= i;
			break;
		default:
			throw InvalidInputException();
			break;
	}

	return result;
}

int RPN::process(const std::string &input)
{
	std::queue<char> queue = parse(input);
	if (queue.empty())
		return 0;

	char c = frontPop(queue);
	if (!isdigit(c))
		throw InvalidInputException();

	int result = c - '0';
	while (!queue.empty())
		result = execute(queue, result);
	
	return result;
}

RPN &RPN::operator=(const RPN &other)
{
	(void) other;
	return *this;
}
