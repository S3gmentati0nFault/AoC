#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	ifstream f("input.txt");
	if (!f.is_open())
	{
		cout << "Could not open the file" << endl;
		return -1;
	}

	string corr_mem;

	// Store the values in the vector
	string line;
	while (getline(f, line))
	{
		corr_mem += line;
	}

	//cout << corr_mem << endl;

	// Part one
	regex multiply("mul\\((\\d{1,3}),(\\d{1,3})\\)");
	long sum = 0;
	for (auto it = sregex_iterator(corr_mem.begin(), corr_mem.end(), multiply);
			it != sregex_iterator(); ++it)
	{ 
		smatch match = *it;	

		int a = stoi(match[1].str());
		int b = stoi(match[2].str());
		sum += a * b;
	}

	cout << sum << endl;

	// Part two
	regex boolCondition("(?:do\\(\\))|(?:don't\\(\\))|(mul)\\((\\d{1,3}),(\\d{1,3})\\)");
	bool doMultiplication = true;
	sum = 0;
	for (auto it = sregex_iterator(corr_mem.begin(), corr_mem.end(), boolCondition);
			it != sregex_iterator(); ++it)
	{ 
		smatch match = *it;
		
		// Changing whether I keep count of multiplications or not
		if (match[0].str() == "do()") {
			doMultiplication = true;
		}
		else if (match[0].str() == "don't()") {
			doMultiplication = false;
		}
		// Do the multiplication only if the last modifier says to do so
		else if (match[1] == "mul" && doMultiplication) {
			int a = stoi(match[2].str());
			int b = stoi(match[3].str());
			sum += a * b;
		}
	}

	cout << sum << endl;

	f.close();
	return 0;
}
