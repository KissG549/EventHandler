#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
#include <Event.h>
#include "KeyEventListener.h"

const std::string usage = "Enter words or numbers delimited by spaces!";

int main()
{
	std::string line;
	std::string word;
	std::stringstream ss;

	cae::Event eventNum;
	cae::Event eventStr;

	std::vector<cae::EventArgs*> argsVector;

	cae::KeyEventListener eventListener(eventNum, eventStr);
	
	std::cout << usage << std::endl;

	/* 
		- read a line
		- process the words
		- raise the appropriate event
	*/

	std::getline(std::cin, line);
	ss << line;

	while (ss >> word)
	{
		std::cout << word << std::endl;

		/*
			String or Number ?

			String: a-zA-Z0-9
		
			Number:
				decimal	0-9
				floating point 0-9.0-9
				hexadecimal 0-9a-fA-F
		*/

		std::stringstream converter(word);
		cae::EventArgs* args;

		if (std::regex_match(word.c_str(), std::regex("[0-9A-Fa-f]+"))
			|| std::regex_match(word.c_str(), std::regex("^[0-9]+[.][0-9]+$")))
		{
			args = new cae::KeyEventArgs<std::string>(eventNum, word);
		}
		else
		{
			args = new cae::KeyEventArgs<std::string>(eventStr, word);
		}
		
		eventStr.Raise(*args);
		argsVector.push_back(args);
	}
	
	for (auto it : argsVector)
	{
		delete it;
	}

	return 0;
}