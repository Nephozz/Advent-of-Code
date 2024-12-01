#include <iostream>
#include <fstream>

using namespace std;

int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int isForbidden(string s) {
    return s.find("ab") != string::npos || s.find("cd") != string::npos || s.find("pq") != string::npos || s.find("xy") != string::npos;
}

int isPairWithoutOverlap(string s) {
    for (int i = 0; i < (int)s.length() - 1; i++) {
        if (s.find(s.substr(i, 2), i + 2) != string::npos) return 1;
    }
    return 0;
}

int isRepeatingLetter(string s) {
    for (int i = 0; i < (int)s.length() - 2; i++) {
        if (s[i] == s[i + 2]) return 1;
    }
    return 0;
}

int main() {

    ifstream file("inputs/day5");
    string line;
    int nice = 0;
    int nice2 = 0;

    while (getline(file, line)) {
        int vowels = 0;
        int doubleLetter = 0;
        int forbidden = 0;
        int pairWithoutOverlap = 0;
        int repeatingLetter = 0;

        for (int i = 0; i < (int)line.length(); i++) {
            if (isVowel(line[i])) vowels++;
            if (line[i] == line[i + 1]) doubleLetter++;
            if (isForbidden(line.substr(i, 2))) forbidden++;
            if (isPairWithoutOverlap(line)) pairWithoutOverlap++;
            if (isRepeatingLetter(line)) repeatingLetter++;
        }

        if (vowels >= 3 && doubleLetter > 0 && forbidden == 0) nice++;
        if (pairWithoutOverlap > 0 && repeatingLetter > 0) nice2++;
    }

    cout << "Answer: " << nice << endl;
    cout << "Answer 2: " << nice2 << endl;

    return 0;
}