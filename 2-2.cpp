#include <iostream>
#include <fstream>
#include <string>

int main () {
	std::string line;
	std::ifstream file("./Input/2.txt");
	//std::ifstream file("./Input/test.txt");

	int horizontalPos = 0;
	int depth = 0;
	int aim = 0;

	
	std::string command;
	int value;

	while (getline(file, line)) { //datei zeilenweise auslesen
		// Beispielzeile: "forward 3"

		std::string delimiter = " ";
		command = line.substr(0, line.find(delimiter)); // String vor dem leerzeichen
		value = stoi(line.substr(line.find(delimiter)+1)); // string nach dem leerzeichen --> als int

		/*std::cout << command;
		std::cout << "---";
		std::cout << value;*/

		// verändern des jeweiligen wert je nach anweisung (command)
		if (command == "forward") {
			horizontalPos += value;
			depth += (value * aim);
		} else if (command == "down") {
			aim += value;
		} else if (command == "up") {
			aim -= value;
		}

		/*std::cout << std::endl;*/		
	}

	// Output
	std::cout << "Horizontal position: ";
	std::cout << horizontalPos << std::endl;

	std::cout << "Depth: ";
	std::cout << depth << std::endl;

	std::cout << "Endvaalue: ";
	std::cout << horizontalPos*depth << std::endl;

	file.close();
	return 0;
}