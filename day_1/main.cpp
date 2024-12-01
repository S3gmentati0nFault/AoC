#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ifstream f("input.txt");
	if (!f.is_open()) {
		cout << "Could not open the file" << endl;
		return -1;
	}

	vector<int> v1, v2;

	// Store the values in the vector
	int i = 0;
	int number;
	while (f >> number) {
		if (i % 2 == 0) {
			v1.push_back(number);
		}
		else {
			v2.push_back(number);
		}
		++i;
	}

	// Sort the two arrays
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int size = v1.size();

	// Compute the distance between the two vectors
	int distance = 0;
	for (int i = 0; i < size; ++i) {
		int diff = v1[i] - v2[i];
		distance += abs(diff);
	}

	cout << distance << endl;

	// Compute the similarity score
	int similarity = 0;
	for (int i = 0; i < size; ++i) {
		int occ = max(0, static_cast<int>(count(v2.begin(), v2.end(), v1[i])));
		similarity += (occ * v1[i]);
	}

	cout << similarity << endl;

	return 0;
}
