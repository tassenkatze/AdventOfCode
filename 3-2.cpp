#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <bitset>

using namespace std;

int main () {
	string line;
	ifstream file("./Input/3.txt");
	//ifstream file("./Input/test.txt");

	int n; // anzahl stellen der zahlen des inputs

	while(getline(file,line)) { // einmalig größe der binärnummern herausfinden
		n = line.size();
		//cout << n << "-n-" << endl;
		break;
	}
	file.clear(); // clear flags (like EOF) 
	file.seekg(0); // move to beginning

	// zählen an nullen und einsen (jeweils für oxygen und co2)
	int oxygenZeroCount;
	int oxygenOneCount;
	int co2ZeroCount;
	int co2OneCount;

	//endwerte als array
	int oxygenArray[n];
	int co2Array[n];

	bool oxygenMatch;
	bool co2Match;

	for (int i = 0; i < n; i++) {
		//cout << "äußerer for-loop" << endl;
		oxygenOneCount = 0;
		oxygenZeroCount = 0;
		co2OneCount = 0;
		co2ZeroCount = 0;

		int oxygenAnzahlWerte = 0;
		int oxygenLetzterWert = 0; 
		int co2AnzahlWerte = 0;
		int co2LetzterWert = 0;

		while (getline(file, line)) { // auswerten der derzeitigen stellen
			//cout << line << endl;
			oxygenMatch = true;
			co2Match = true;
			for (int j = 0 ; j < i; j++) { // überprüfung, ob aktuelle zeile ausgewertet werden soll
				/*// test:
				cout << "j=" << j << " i=" << i << endl;
				cout << stoi(line.substr(j, 1)) << "--";
				cout << oxygenArray[j] << "--";
				cout << co2Array[j] << endl;*/
				if ((stoi(line.substr(j, 1)) != oxygenArray[j]) && (stoi(line.substr(j, 1)) != co2Array[j])) {
					oxygenMatch = false; 
					co2Match = false;
					break;
				}
				if (stoi(line.substr(j, 1)) != oxygenArray[j]){
					oxygenMatch = false; 
				}
				if (stoi(line.substr(j, 1)) != co2Array[j]){
					co2Match = false;
				}

			}
			if (oxygenMatch) { // true --> aktuelle zeile ausgewertet
				++oxygenAnzahlWerte;
				oxygenLetzterWert = stoi(line.substr(i, 1));
				if (line.substr(i, 1) == "0") {
					++oxygenZeroCount;
				} 
				if ( line.substr(i, 1) == "1") {
					++oxygenOneCount;
				}
			}
			if (co2Match) { // true --> aktuelle zeile ausgewertet
				++co2AnzahlWerte;
				co2LetzterWert = stoi(line.substr(i, 1));
				if (line.substr(i, 1) == "0") {
					++co2ZeroCount;
				} 
				if ( line.substr(i, 1) == "1") {
					++co2OneCount;
				}
			}


		}
		file.clear();
		file.seekg(0);
		if (oxygenAnzahlWerte == 1) {
			oxygenArray[i] = oxygenLetzterWert;

		} else if (oxygenOneCount >= oxygenZeroCount) {
			oxygenArray[i] = 1;
		} else {
			oxygenArray[i] = 0;

		} 
		if (co2AnzahlWerte == 1) {
			co2Array[i] = co2LetzterWert;

		} else if (co2OneCount >= co2ZeroCount) {
			co2Array[i] = 0;
		} else {
			co2Array[i] = 1;

		} 
		// test;
		cout << "oxygen: ";
		for (int h = 0; h <= i; h++) {
			cout << oxygenArray[h];
			cout << "-";	
		}
		cout << " co2: ";
		for (int h = 0; h <= i; h++) {
			cout << co2Array[h];
			cout << "-";	
		}
		cout << endl;


	}

	// Ausgabe Test
	cout << "oxygen: ";
	for (int i = 0; i < n; i++) {
		cout << oxygenArray[i];
		cout << "-";	
	}
	cout << " co2: ";
	for (int i = 0; i < n; i++) {
		cout << co2Array[i];
		cout << "-";	
	}
	cout << endl;


	string oxygenString = "";
	string co2String = "";
	for (int i = 0; i < n; i++) { // concat zu int
		oxygenString.append(std::to_string(oxygenArray[i]));
		co2String.append(std::to_string(co2Array[i]));				
	}

	//cout << "test oxygenString" << oxygenString << endl;

	bitset<128> oxygenBits(oxygenString); // als bitset speichern
	int oxygenDec = oxygenBits.to_ulong(); // in dezimal umwandeln
	bitset<128> co2Bits(co2String); // als bitset speichern
	int co2Dec = co2Bits.to_ulong(); // in dezimal umwandeln

	// Ausgabe Test
	cout << "oxygenDec: ";
	cout << oxygenDec;
	cout << " co2Dec: ";
	cout << co2Dec;
	cout << endl;


	int lifeSupportRating = oxygenDec * co2Dec;
	cout << "lifeSupportRating: ";
	cout << lifeSupportRating;

	cout << std::endl;
	return 0;
}