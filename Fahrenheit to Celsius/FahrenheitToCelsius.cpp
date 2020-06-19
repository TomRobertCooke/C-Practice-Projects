#include <iostream>
#include <string>
#include <sstream>

double getCelsius(double f);

int main() {
	double fdegrees = 0.0;
	std::string degreestr = "";
	while (true) {
		std::cout << "Type in the number you wish to convert (\"exit\" to close the program): ";
		getline(std::cin, degreestr);
		if (degreestr.compare("exit") == 0) {
			std::cout << "Goodbye" << std::endl;
			return 0;
		}
		if (!(std::stringstream(degreestr) >> fdegrees)) {
			std::cout << "Not a number, try again" << std::endl;
			continue;
		}
		double cdegrees = getCelsius(fdegrees);
		std::cout << "Your degree value is: " << cdegrees << std::endl;
	}
	return 0;
}

double getCelsius(double f) {
	return (f - 32) * 5 / 9;
}