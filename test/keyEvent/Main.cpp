#include <iostream>
#include <sstream>

const std::string usage = "Simple console application that reads alphanumeric words "
							"(delimited by spaces) from the standard input and raises an "
							"event if the current word is a number (e.g. \"1024\") or a "
							"simple string (e.g. \"apple\").";

int main()
{
	std::string line;
	std::string word;
	std::stringstream ss;

	std::cout << usage << std::endl;

	/* 
		- read a line
		- process the words
		- raise the approrpiate event
	*/

	std::getline(std::cin, line);
	ss << line;

	while (ss >> word)
	{
		std::cout << word << std::endl;

		/*
			String or Number?

			String: a-zA-Z0-9
		
			Number:
				binary	0-1
				decimal	0-9
				floating point 0-9.0-9
				hexadecimal 0-F
				octal 0-8
				scientific - 0-9.0-9e+-0-9
		*/
	}
	
	return 0;
}