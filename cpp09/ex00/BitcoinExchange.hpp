#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange
{

private:
	static const std::string database;
	std::string file;
	std::map<std::string, float> content;

	void loadDatabase();
	void processInput();

public:
	BitcoinExchange(const std::string &file);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &other);

	class InvalidFileException: std::exception
	{ };

};

#endif
