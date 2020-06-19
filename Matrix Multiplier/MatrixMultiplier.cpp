#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	bool open = false;
	ifstream fileIn;
	while (!open) {
		cout << "Filename: ";
		string filename = "";
		getline(cin, filename);
		fileIn.open(filename);
		if (fileIn.is_open()) {
			open = true;
		}
		else {
			cout << "File not found, try again" << endl;
		}
	}
	string line;
	getline(fileIn, line);

	return 0;
}
