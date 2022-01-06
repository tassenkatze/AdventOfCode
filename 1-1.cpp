// adventOfCode
// https://adventofcode.com/2021

#include <iostream>
#include <fstream>
#include <string>

int main () {
	std::string line;
	int thisNum;
	int prevNum;
	int counter = 0;
	bool firstLine = false;


	std::ifstream file("./Input/1.txt"); // datei zum lesen geöffnet
	//std::ifstream file("test.txt");

	while (getline(file, line)) { //datei zeilenweise auslesen

		//std::cout << line;

		thisNum = stoi(line); // umwandlung string (zeile) in int

		if (firstLine){ // um codeblock bei erstem durchlauf zu überpringen
			if (thisNum > prevNum) { 
				++counter; // mitzählen falls wert gestiegen
			}
		}		

		prevNum = thisNum; //speichern vorheriger wert
		firstLine = true; // ab erstem durchlauf immer alles ausführen
	}
	file.close(); // datei schließen

	// Ausgabe
	std::cout << "Number of increases: ";
	std::cout << counter << std::endl;
	
	return 0;
}
