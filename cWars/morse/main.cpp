#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> morse = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-",
    "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----.", "-----", "--..--", "..--..",
    "...---...", "-.-.--",
    ".-.-.-"
};

std::vector<std::string>
    letter = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
        "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V",
        "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7",
        "8", "9", "0", ",", "?", "SOS", "!", "." };

std::map<std::string, std::string> fillMap(
    std::vector<std::string> inputMorse, std::vector<std::string> letterMaps)
{
    std::map<std::string, std::string> morseMap;

    for (size_t i = 0; i < inputMorse.size(); i++) {
        morseMap[inputMorse[i]] = letterMaps[i];
    }
    return morseMap;
}

/* Tokenizing a string */
std::vector<std::string> tokenizeString(const std::string& inputString,
    std::string delimiter)
{
    std::vector<std::string> tokens;
    std::string inputCopy = inputString;
    inputCopy.append("   ");

    size_t pos = 0;
    std::string token;
    while ((pos = inputCopy.find(delimiter)) != std::string::npos) {
        token = inputCopy.substr(0, pos);
        tokens.push_back(token);
        inputCopy.erase(0, pos + delimiter.length());
        tokens.push_back(" ");
    }

    return tokens;
}

std::vector<std::string> characterizeTokens(
    std::vector<std::string> inputVector)
{
    std::string temp;
    std::vector<std::string> tokens;

    for (auto words : inputVector) {
        if (words == " ") {
            tokens.push_back(" ");
        }
        std::stringstream ss(words);
        while (
            getline(ss, temp, ' ')) { // use comma as delim for cutting string
            tokens.push_back(temp);
        }
    }
    return tokens;
}

std::string cleanUpOutput(std::string inputString)
{
    return std::regex_replace(inputString, std::regex("^ + | +$"), "");
}

std::string decodeMorse(std::string morseCode)
{
    std::regex_replace(morseCode, std::regex("^ +"), "");
    std::string decoded;
    std::cout << "Input: " << morseCode << std::endl;

    // generate associative array
    auto morseLookup = fillMap(morse, letter);

    // fill a vector with each word
    std::vector<std::string> words = tokenizeString(morseCode, "   ");

    std::vector<std::string> letters = characterizeTokens(words);

    for (auto things : letters) {
        if (things == " ") {
            decoded.append(" ");
        }
        std::map<std::string, std::string>::iterator it = morseLookup.find(things);
        if (it == morseLookup.end()) {
            continue;
        } else {
            decoded.append(it->second);
        }
    }
    return cleanUpOutput(decoded);
}

int main()
{
    std::string answer = decodeMorse(".... . -.--   .--- ..- -.. .");
    std::cout << answer << std::endl;
    std::string longInput = "...---... -.-.--   - .... .   --.- ..- .. -.-. -.-   -... .-. --- .-- "
                            "-.   ..-. --- -..-   .--- ..- -- .--. ...   --- ...- . .-.   - .... . "
                            "  .-.. .- --.. -.--   -.. --- --. .-.-.-   ";
    std::cout << decodeMorse(longInput);

    return 0;
}
