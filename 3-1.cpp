#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <bitset>

using namespace std;

int main () {
	string line1;
	string line2;
	ifstream file1("./Input/3.txt");
	ifstream file2("./Input/3.txt");
	/*ifstream file1("./Input/test.txt");
	ifstream file2("./Input/test.txt");*/

	int n; // anzahl stellen der zahlen des inputs



	while(getline(file1,line1)) { // einmalig größe der binärnummern herausfinden
		n = line1.size();
		//cout << n << "-n-" << endl;
		break;
	}
	file1.close();

	// anzahl an werten getrennt nach stelle in string
	double zeroCount[n];
	double oneCount[n];

	for (int i = 0; i < n; i++) { // Initisalisierung
		zeroCount[i] = 0;
		oneCount[i] = 0;
	}

	// berechnen der anzahl an nullen und einsen
	while (getline(file2, line2)) { //datei zeilenweise auslesen
		// cout << line2 << endl; // Test
		for(string::size_type i = 0; i < n; ++i) { // string characterweise auslesen
			if (line2.substr(i, 1) == "0") {
				++zeroCount[i];
			} 
			if (line2.substr(i, 1) == "1") {
				++oneCount[i];
			}		
		}
	}
	file2.close();

	// Ausgabe Test
	cout << "zeroCount: ";
	for (int i = 0; i < n; i++) {
		cout << zeroCount[i];
		cout << "-";	
	}

	cout << " oneCount: ";
	for (int i = 0; i < n; i++) {
		cout << oneCount[i];
		cout << "-";	
	}
	cout << endl;


	int gammaRateArray[n];
	int epsilonRateArray[n];
	for (int i = 0; i < n; i++) {
		if (zeroCount[i] > oneCount[i]) {
			gammaRateArray[i] = 0;
			epsilonRateArray[i]= 1;
		}
		if (zeroCount[i] < oneCount[i]) {
			gammaRateArray[i] = 1;
			epsilonRateArray[i] = 0;
		}
	}


	// Ausgabe Test
	cout << "gammaRate: ";
	for (int i = 0; i < n; i++) {
		cout << gammaRateArray[i];
		cout << "-";	
	}
	cout << " epsilonRate: ";
	for (int i = 0; i < n; i++) {
		cout << epsilonRateArray[i];
		cout << "-";	
	}
	cout << endl;


	string gammaRate = "";
	string epsilonRate = "";
	for (int i = 0; i < n; i++) { // concat zu int
		gammaRate.append(std::to_string(gammaRateArray[i]));
		epsilonRate.append(std::to_string(epsilonRateArray[i]));				
	}

	cout << "test gammaRate " << gammaRate << endl;

	bitset<128> gammaBits(gammaRate); // als bitset speichern
	int decGamma = gammaBits.to_ulong(); // in dezimal umwandeln
	bitset<128> epsilonBits(epsilonRate); // als bitset speichern
	int decEpsilon= epsilonBits.to_ulong(); // in dezimal umwandeln

	// Ausgabe Test
	cout << "decGamma: ";
	cout << decGamma;
	cout << " decEpsilon: ";
	cout << decEpsilon;
	cout << endl;


	int powerConsumption = decGamma * decEpsilon;
	cout << " powerConsumption: ";
	cout << powerConsumption;

	cout << std::endl;
	return 0;
}