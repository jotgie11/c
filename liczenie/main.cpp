#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int stringToInt(string word) {
    string uniqueChars = "";
    for (int i = 0; i < word.length(); i++) {
        char c = word[i];
        bool duplicate = false;
        for (int j = 0; j < i; j++) {
            if (word[j] == c) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            uniqueChars += c;
        }
    }

    int result = 0;
    for (int i = 0; i < uniqueChars.length(); i++) {
        char c = uniqueChars[i];
        int letterValue = c - 'a' + 1;
        result += letterValue;
    }
    return result;
}
int main() {
    fstream plik;
    plik.open("plik.txt", ios::in);

    if (!plik.good()) {
        cout << "Problem z otwarciem pliku." << endl;
        return 1;
    }


    string longestWord;
    string shortestWord;
    string word;





    while (plik >> word) {
        cout << word << endl;
        cout << endl;
        if (word.length() < 1 || word.length() > 100) {
            continue;
        }
        if (word.length() > longestWord.length()) {
            longestWord = word;
        }

        if (shortestWord.empty() || word.length() < shortestWord.length()) {
            shortestWord = word;
        }

        string newWord;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            bool pow = false;
            for (int j = 0; j < newWord.length(); j++) {
                if (newWord[j] == c) {
                    pow = true;
                    break;
                }
            }
            if (!pow) {
                newWord += c;
            }
        }

    }
        cout << shortestWord << " = ";
        cout << stringToInt(shortestWord) << endl;

        cout << longestWord << " = ";
        cout << stringToInt(longestWord) << endl;

        cout << "Najdluzsze slowo: " << longestWord << endl;
        cout << "Najkrotsze slowo: " << shortestWord << endl;




    plik.close();



    return 0;
}
