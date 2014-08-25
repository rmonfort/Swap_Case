#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	// Get a line and go through it char by char
	while (getline(ifs, line))
	{
		for (auto &c : line)
		{
			if (isupper(c))
			{
				c = tolower(c);	
			}
			else
			{
				c = toupper(c);
			}
			cout << c;
		}
		cout << endl;
	}
	return 0;
}