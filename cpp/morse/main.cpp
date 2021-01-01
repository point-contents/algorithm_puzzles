#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> morse = {
    ".-",    "-...",  "-.-.",  "-..",   ".",      "..-.",   "--.",   "....",
    "..",    ".---",  "-.-",   ".-..",  "--",     "-.",     "---",   ".--.",
    "--.-",  ".-.",   "...",   "-",     "..-",    "...-",   ".--",   "-..-",
    "-.--",  "--..",  ".----", "..---", "...--",  "....-",  ".....", "-....",
    "--...", "---..", "----.", "-----", ".-.-.-", "--..--", "..--.."};

std::vector<std::string> letter = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",    "L", "M",
    "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X",    "Y", "Z",
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "Stop", ",", "?"};

std::map<std::string, std::string> fillMap(
    std::vector<std::string> inputMorse, std::vector<std::string> letterMaps) {
    std::map<std::string, std::string> morseMap;

    for (size_t i = 0; i < inputMorse.size(); i++) {
	morseMap[inputMorse[i]] = letterMaps[i];
    }
    return morseMap;
}

/* Tokenizing a string */
std::vector<std::string> tokenizeString(const std::string& inputString,
					std::string delimiter) {
    std::vector<std::string> tokens;
    std::string inputCopy = inputString;
	inputCopy.append("   ");

    size_t pos = 0;
    std::string token;
    while ((pos = inputCopy.find(delimiter)) != std::string::npos) {
	token = inputCopy.substr(0, pos);
	tokens.push_back(token);
	inputCopy.erase(0, pos + delimiter.length());
    }

    return tokens;
}

std::vector<std::string> characterizeTokens(std::vector<std::string> inputVector)
{
	std::string temp;
	std::vector<std::string> tokens;

	for(auto words: inputVector)
	{
		std::stringstream ss(words);
		while(getline(ss, temp, ' '))
		{ //use comma as delim for cutting string
		  tokens.push_back(temp);
		}
	}
	return tokens;
}

void printMap(std::map<std::string,std::string> inputMap)
{
	for(auto mappies: inputMap)
	{
		std::cout << mappies.first << std::endl;
		std::cout << mappies.second << std::endl;
	}

}

std::string decodeMorse(std::string morseCode) {
	//generate associative array
    auto morseLookup = fillMap(morse, letter);
//	printMap(morseLookup);
	//answer placeholder
    std::string decoded;
	//fill a vector with each word
    std::vector<std::string> words = tokenizeString(morseCode, "   ");

    for (auto shit : words) std::cout << shit << std::endl;
	//split word vector into separate letters
	std::vector<std::string> letters = characterizeTokens(words);

	for(auto things: letters)
	{
		std::cout << things << std::endl;
		std::map<std::string,std::string>::iterator it = morseLookup.find(things);
		if(it == morseLookup.end())
		{
			std::cout << "NAH I cant find: " << things << std::endl;
		}
		else
		{
			std::cout << it->second << std::endl;
		}
		decoded.append(things);
	}
    return decoded;
}


int main() {
	std::string answer =  decodeMorse(".... . -.--   .--- ..- -.. .");
	std::cout << answer << std::endl;

    return 0;
}
