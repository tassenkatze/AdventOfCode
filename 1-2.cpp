#include <iostream>
#include <fstream>
#include <string>

int main () {
	std::string line;
	int lineNum;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int thisNum;
	int prevNum;
	int counter = 0;
	int start = 0;
	std::ifstream file("./Input/1.txt"); // datei zum lesen geöffnet

	while (getline(file, line)) { //datei zeilenweise auslesen

		lineNum = stoi(line); // umwandlung in int

		// werte für letzte drei zeilen erhöhen
		num1 = num2;
		num2 = num3;
		num3 = lineNum;

		thisNum = num1 + num2 + num3; //jetziger wert

		if (start > 2){ //start erst nach 3 durchläufen
			if (thisNum > prevNum) {
				++counter; // zähler an increases
			}
		}		

		prevNum = thisNum; // vorheriger wert
		++start; // Für start des vergleiches
	}

	std::cout << "Number of increases: ";
	std::cout << counter << std::endl;

	file.close();
	return 0;
}