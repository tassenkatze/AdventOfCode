#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool hasBingo(vector<bool> bingofeldBools);

int getBoardScore(vector<int> bingofeld, vector<bool> bingofeldBools);

// BINGO
int main () {
	string line;
	ifstream file("./Input/4.txt");
	//ifstream file("./Input/test.txt");

	vector<int> bingozahlen; // vector mit allen bingozahlen

	while(getline(file,line)) { // erste zeile auslesen, bingozahlen in array
		//cout << "zahlen: " << line << endl;
		string delimiter = ",";
		size_t pos = 0;
		while ((pos = line.find(delimiter)) != string::npos) { // auslesen der werte zwischen delimiter
			int token = stoi(line.substr(0, pos)); // ausgelesener wert
			bingozahlen.push_back(token); // speichern in vector
			line.erase(0, pos + delimiter.length()); // jetzigen wert entfernen
		}
		bingozahlen.push_back(stoi(line)); // letzter wert übernehmen
		break;
	} // kein zurücksetzen der datei --> erste zeile wird beim nächsten mal übersprungen

	// Ausgabe Test
	cout << "bingozahlen: ";
	for (int i = 0; i < bingozahlen.size(); i++) {
		cout << bingozahlen[i];
		cout << "-";	
	}
	cout << "anzahl bingozahlen: " << bingozahlen.size() << endl << endl;


	/*Auswertung bingofelder:	
	Idee: 
	1. bei welcher zahl wird komplette reihe oder spalte erreicht --> speichern (bingoausruf)
	2. score errechnen (übrige zahlen addiert * letzte aufgerufene bingozahl)
	3. nächstes feld auswerten
	4. falls früher fertig: vorheriges bingo und score überschreiben*/


	int bingo; // stelle der bingozahl, die zu bingo führt
	int score; // endwert

	
	vector<int> bingofeld;
	vector<bool> bingofeldBools;
	int zeilenzähler = 0;

	int endscore;
	int currentBestBingo = 0;

	while(getline(file,line)) {
		++zeilenzähler;

		if ((zeilenzähler % 6) == 1) { // überspringen der zeilen mit leerzeichen
			//cout << " zeile mit leerzeichen" << endl;
			continue; 
		}

		//cout << "zeile " << zeilenzähler << ": " << line << endl; // Test

		// Zeile auslesen
		string delimiter = " ";
		size_t pos = 0;
		while ((pos = line.find(delimiter)) != string::npos) { // auslesen der werte zwischen delimiter
			string substring = line.substr(0, pos);
			if (substring.length() != 0) { // leere substrings bei einstelligen zahlen überspringen
				int token = stoi(line.substr(0, pos)); // ausgelesener wert
				bingofeld.push_back(token); // speichern in vector
				bingofeldBools.push_back(false);
			}
			line.erase(0, pos + delimiter.length()); // jetzigen wert entfernen
		}
		bingofeld.push_back(stoi(line));
		bingofeldBools.push_back(false);
		
		//cout << " zeilenauslesen fertig" << endl;

		if ((zeilenzähler % 6) == 0) { // ein bingofeld nun komplett ausgelesen --> auswertung des feldes
			
			cout << "feld: ";
			for (int j = 0; j < bingofeld.size(); j++) {
				cout << bingofeld[j];
				cout << "-";	
			}
			cout << endl;


			for (int indexBingozahl = 0; indexBingozahl < bingozahlen.size(); ++indexBingozahl) { 
				for (int indexBingofeld = 0; indexBingofeld < bingofeld.size(); ++indexBingofeld) {
					if (bingofeld[indexBingofeld] == bingozahlen[indexBingozahl]) { // bingozahl in feld gefunden
						bingofeldBools[indexBingofeld] = true;
						//cout << "zahl " << bingozahlen[indexBingozahl] << " ist in bingofeld vorhanden" << endl;
					}					
				}
				if (hasBingo(bingofeldBools)) {
					if (indexBingozahl > currentBestBingo) {
						currentBestBingo = indexBingozahl;
						cout << "besseres bingo bei " << indexBingozahl << " bingozahlen" << endl; 
						endscore = getBoardScore(bingofeld, bingofeldBools) * bingozahlen[indexBingozahl];
						
					} else {
						cout << "bingo bei " << indexBingozahl << " bingozahlen" << endl; 
					}
					// bingozahlen.erase(bingozahlen.begin() + indexBingozahl, bingozahlen.end());
					break;
				}
				
			}

			cout << endl;
			bingofeld.clear();
			bingofeldBools.clear();

		}
		
	}

	cout << "endscore: " << endscore << endl;

	cout << endl;
	return 0;
}


bool hasBingo(vector<bool> bingofeldBools) {
	bool bingo;
	for (int indexReihe = 0; indexReihe < 5; ++indexReihe){
		bingo = true;
		for (int indexElement = 0; indexElement < 5; ++indexElement){
			int index = indexReihe*5 + indexElement;
			if (!bingofeldBools[index]) {
				bingo = false;
				break;
			}
		}
		if (bingo) return bingo;
	}
	for (int indexSpalte = 0; indexSpalte < 5; ++indexSpalte){
		bingo = true;
		for (int indexElement = 0; indexElement < 5; ++indexElement){
			int index = indexSpalte + indexElement*5;
			if (!bingofeldBools[index]) {
				bingo = false;
				break;
			}
		}
		if (bingo) return bingo;
	}	

	return bingo;
}


int getBoardScore(vector<int> bingofeld, vector<bool> bingofeldBools) {
	int score = 0;
	for (int i = 0; i < bingofeld.size(); ++i) {
		if (!bingofeldBools[i]) {
			//cout << "wert " << bingofeld[i] << endl;
			score += bingofeld[i];
		}
	}
	cout << "score = " << score << endl;
	return score;
}



/*int currentbestBingo
int currentScore
min_anzahl_bingozahlen = len(bingozahlen)
vector<bool> bingofeldBools
for bingofeld in alleBingofelder:
	for index_bingozahl in bingozahlen:
		find bingozahl in bingofeld --> index
		bingofeldBools[index] = true
		if has_bingo(bingofeldBools)
			if index_bingozahl < currentbestBingo
				currentbestBingo = index_bingozahl
				currentScore = get_score(bingofeld, bingofeldBools)




def has_bingo(bingofeldBools)	
	for index_reihe in range(5):
		is_bingo = True
		for index_elem in range(5)
			index = index_reihe*5 + index_elem
			if bingofeldBools[index] == False:
				is_bingo = False
				break;
		if is_bingo:
			return True
	for index_spalte in range(5):
		is_bingo = True
		for index_elem in range(5)
			index = index_spalte + index_elem*5
			if bingofeldBools[index] == False:
				is_bingo = False
				break;
		if is_bingo:
			return True

	return False

def get_score (bingofeld, bingofeldBools)
	score = 0;
	for index in range(25)
		if bingofeldBools[index] == False
			score += bingofeld[index]
	return score;*/



