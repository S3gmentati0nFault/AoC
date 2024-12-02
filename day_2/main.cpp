#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream f("input.txt");
	if (!f.is_open()) {
		cout << "Could not open the file" << endl;
		return -1;
	}

	vector<int> data;

	// Store the values in the vector
	int number;
	while (f >> number) {
		data.push_back(number);
	}

	cout << data.size() << endl;
	return 0;
}
