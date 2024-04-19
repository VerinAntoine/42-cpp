#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: filename s1 s2" << std::endl;
		return 1;
	}

	std::string filename = std::string(argv[1]);
	std::string s1 = std::string(argv[2]);
	std::string s2 = std::string(argv[3]);
	std::string content;

	std::ifstream ifile(filename.c_str());
	if (!ifile.is_open())
	{
		std::cerr << "Couldn't open file " << filename << std::endl;
		return 2;
	}
	std::ofstream ofile(filename.append(".replace").c_str());
	if (!ofile.is_open())
	{
		std::cerr << "Couldn't open replaced file " << filename << std::endl;
		ifile.close();
		return 2;
	}

	while (std::getline(ifile, content))
	{
		size_t index = content.find(s1);
		while (index != std::string::npos)
		{
			content = content.erase(index, s1.length());
			content = content.insert(index, s2);
			index = content.find(s1);
		}
		ofile << content << std::endl;
	}
	ifile.close();
	ofile.close();
	return 0;
}
