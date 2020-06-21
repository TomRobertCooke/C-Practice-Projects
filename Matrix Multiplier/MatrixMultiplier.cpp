#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::string;
using std::cin;
using std::endl;
using std::cout;
using std::ifstream;
using std::stringstream;

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
	int arows, acols;
	if (!getline(fileIn, line)) {
		cout << "Missing line" << endl;
		return 0;
	}

	stringstream readNums(line);
	if (!(readNums >> arows) || !(readNums >> acols)) {
		cout << "Incorrect input format" << endl;
		return 0;
	}
	
	int amat[arows][acols];
	for (int i = 0; i < arows; i++) {
		if (!getline(fileIn, line)) {
			cout << "Missing line" << endl;
			return 0;
		}
		readNums.clear();
		readNums.str(line);
		for (int j = 0; j < acols; j++) {
			//cout << readNums.str() << endl;
			readNums >> amat[i][j];
			if (readNums.fail()) {
				cout << "Missing a number in matrix A" << endl;
				return 0;
			}
		}
	}

	cout << endl << "Matrix A:" << endl;
	for (int i = 0; i < arows; i++) {
		for (int j = 0; j < acols; j++) {
			cout << amat[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	int brows, bcols;
	if (!getline(fileIn, line)) {
		cout << "Missing line" << endl;
		return 0;
	}

	readNums.clear();
	readNums.str(line);
	if (!(readNums >> brows) || !(readNums >> bcols)) {
		cout << "Incorrect input format" << endl;
		return 0;
	}

	int bmat[brows][bcols];
	for (int i = 0; i < brows; i++) {
		if (!getline(fileIn, line)) {
			cout << "Missing line" << endl;
			return 0;
		}
		readNums.clear();
		readNums.str(line);
		for (int j = 0; j < bcols; j++) {
			//cout << readNums.str() << endl;
			readNums >> bmat[i][j];
			if (readNums.fail()) {
				cout << "Missing a number in matrix B" << endl;
				return 0;
			}
		}
	}

	cout << "Matrix B:" << endl;
	for (int i = 0; i < brows; i++) {
		for (int j = 0; j < bcols; j++) {
			cout << bmat[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	if (acols != brows) {
		cout << "";
	}

	int abmat[arows][bcols];
	for (int i = 0; i < arows; i++) {
		for (int j = 0; j < bcols; j++) {
			int sum = 0;
			for (int k = 0; k < acols; k++) {
				sum += amat[i][k] * bmat[k][j];
			}
			abmat[i][j] = sum;
		}
	}

	cout << "Matrix A*B:" << endl;
	for (int i = 0; i < arows; i++) {
		for (int j = 0; j < bcols; j++) {
			cout << abmat[i][j] << "\t";
		}
		cout << endl << endl;
	} 

	return 0;
}
