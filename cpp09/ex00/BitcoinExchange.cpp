#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

#define SPACES " \t\n\r\f\v"

const std::string BitcoinExchange::database = "data.csv";

BitcoinExchange::BitcoinExchange(const std::string &file)
: file(file)
{
	loadDatabase();
	processInput();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
: file(other.file)
{ }

BitcoinExchange::~BitcoinExchange() { }

static void trim(std::string& str)
{
	str.erase(str.find_last_not_of(SPACES)+1);
	str.erase(0, str.find_first_not_of(SPACES));
}

static bool verifyDate(std::string date)
{
	size_t cp = date.find('-');
	if (cp == std::string::npos)
		return false;
	char *end;
	long year = std::strtol(date.c_str(), &end, 10);
	if (*end != '-' || year < 2009)
		return false;
	date = date.erase(0, cp + 1);
	cp = date.find('-');
	long month = std::strtol(date.c_str(), &end, 10);
	if (*end != '-' || month < 1 || month > 12)
		return false;
	date = date.erase(0, cp + 1);
	long day = std::strtol(date.c_str(), &end, 10);
	if (*end != 0 || day < 0 || day > 31)
		return false;
	return true;
}

void BitcoinExchange::loadDatabase()
{
	std::ifstream in(database.c_str());
	if (!in.is_open())
		throw InvalidFileException();

	std::string line;
	while (getline(in, line))
	{
		if (line == "date,value")
			continue;
		size_t cp = line.find(',');
		if (cp == std::string::npos || line == "")
			throw InvalidFileException();
		std::string date = line.substr(0, cp);
		std::string value = line.erase(0, cp + 1);
		(trim(date), trim(value));
		if (!verifyDate(date))
			throw InvalidFileException();
		char *end;
		float v = std::strtof(value.c_str(), &end);
		if (*end != 0)
			throw InvalidFileException();
		content.insert(std::pair<std::string, float>(date, v));
	}
}

void BitcoinExchange::processInput()
{
	std::ifstream in(file.c_str());
	if (!in.is_open())
		throw InvalidFileException();
	
	std::string line;
	while (getline(in, line))
	{
		if (line == "date | value")
			continue;
		size_t cp = line.find("|");
		if (cp == std::string::npos)
		{
			std::cout << "bad line: " << line << std::endl;
			continue;
		}
		// std::cout << line << std::endl;
		std::string date = line.substr(0, cp);
		std::string value = line.erase(0, cp + 1);
		(trim(date), trim(value));
		char *end;
		float v = std::strtof(value.c_str(), &end);
		if (*end != 0)
			throw InvalidFileException();
		
		if (v < 0 || v > 1000)
		{
			std::cout << "invalid value " << v << std::endl;
			continue;
		}

		if (!verifyDate(date))
		{
			std::cout << "invalid date for " << date << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator it = content.find(date);
		if (it == content.end())
		{
			std::cout << "no correspondance for " << date << std::endl;
			continue;
		}

		std::cout << date << " => " << v  << " = " << (*it).second * v << std::endl;
	}
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	this->file = other.file;
	return *this;
}
