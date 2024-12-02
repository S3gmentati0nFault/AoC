#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	ifstream f("edge_cases.txt");
	if (!f.is_open())
	{
		cout << "Could not open the file" << endl;
		return -1;
	}

	int size = 10;
	vector<int> *data = new vector<int>[size];

	// Store the values in the vector
	int number;
	int i = 0;
	string line;
	while (getline(f, line))
	{
		istringstream lineStream(line);
		while (lineStream >> number)
		{
			data[i].push_back(number);
		}
		++i;
	}

	// for (int i = 0; i < size; ++i)
	// {
	// 	for (int j = 0; j < data[i].size(); ++j)
	// 	{
	// 		cout << data[i][j] << "  ";
	// 	}
	// 	cout << endl;
	// }

	int safeReports = 0;
	for (int i = 0; i < size; ++i)
	{
		// Behaviour = 1 -- means that the data is increasing
		// Behaviour = -1 -- means that the data is decreasing
		// Behaviour = 0 -- default
		int behaviour = 0;
		bool safe = true;
		bool dampener = true;
		for (int j = 1; j < data[i].size() && safe; ++j)
		{
			int diff = data[i][j - 1] - data[i][j];
			int adiff = abs(diff);

			// Check the first condition
			if (diff == 0)
			{
				safe = false;
			}
			else if (safe && behaviour == 0)
			{
				if (diff > 0)
				{
					behaviour = 1;
				}
				else
				{
					behaviour = -1;
				}
			}
			else
			{
				if ((diff < 0 && behaviour == 1) || (diff > 0 && behaviour == -1))
				{
					safe = false;
				}
			}

			// Check the second condition
			if (safe && (adiff < 1 || adiff > 3))
			{
				safe = false;
			}
		}

		if (safe)
		{
			safeReports++;
		}
	}

	cout << safeReports << endl;

	safeReports = 0;
	for (int i = 0; i < size; ++i)
	{
		int behaviour = 0;
		int dampener = 1;
		bool safe = true;
		for (int j = 1; j < data[i].size() && safe; ++j)
		{
			// Default adjacency
			int diff = data[i][j - 1] - data[i][j];
			// Skip one element
			if (dampener == 0)
			{
				diff = data[i][j - 2] - data[i][j];
				--dampener;
			}
			int adiff = abs(diff);

			// Check the first condition
			if (diff == 0)
			{
				if (dampener > 0)
				{
					--dampener;
					continue;
				}
				else
				{
					safe = false;
				}
			}

			if (behaviour == 0)
			{
				if (diff > 0)
				{
					behaviour = 1;
				}
				else
				{
					behaviour = -1;
				}
			}
			else
			{
				if ((diff < 0 && behaviour == 1) || (diff > 0 && behaviour == -1))
				{
					if (dampener > 0)
					{
						--dampener;
						continue;
					}
					else
					{
						safe = false;
					}
				}
			}

			// Check the second condition
			if (safe && (adiff < 1 || adiff > 3))
			{
				if (dampener > 0)
				{
					--dampener;
				}
				else
				{
					safe = false;
				}
			}
		}

		if (safe)
		{
			safeReports++;
		}
	}

	cout << safeReports << endl;

	f.close();
	return 0;
}