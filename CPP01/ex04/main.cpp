#include <iostream>
#include <string>
#include <fstream> 

int main(int argc, char**argv)
{
	if (argc != 4) {
	std::cerr << "number of arguments must be 3\n";
	return (1);
	}

	// Datei oeffnen
	std::ifstream file;
	file.open(argv[1]);
	if (!file.is_open()) {
    std::cerr << "Fehler beim Öffnen der Datei\n";
	return (1);
	}

	// Dateiinhalt einlesen
	// std::string content;
	// std::string line;

	// while (std::getline(file, line)) {
	// 	content += line + '\n';  // Zeilen zusammenfügen
	// }
	std::string content((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());
	file.close();

	// s1 durch s2 ersetzen
	std::string result;
	size_t pos = 0;
	size_t found = content.find(argv[2], pos);
	while (found != std::string::npos) {
	result += content.substr(pos, found - pos);
	result += argv[3];
	pos = found + std::string(argv[2]).length();
	found = content.find(argv[2], pos);
	}
	result += content.substr(pos);

	// Ergebnis in neue Datei schreiben
	std::string newFilename = std::string(argv[1]) + ".replace";
	std::ofstream outFile(newFilename);
	if (!outFile.is_open()) {
    std::cerr << "Fehler: Neue Datei konnte nicht erstellt werden\n";
    return 1;
	}
	outFile << result;
	outFile.close();
	
	return (0);
}