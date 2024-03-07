# include "functions.h"
# include <iostream>
# include <string>
# include <sstream>
# include <limits>

using std::cout, std::cin, std::endl, std::string;

void deobfuscate() {
    string obfuscatedSentence, lengths, deobfuscatedSentence;
    cout << "Please enter obfuscated sentence: ";
    cin >> obfuscatedSentence;
    cout << "Please enter deobfuscation details: ";
    cin >> lengths;
    int currentLength = 0;
    for (char c : lengths) {
        int wordLength = c - '0';
        deobfuscatedSentence += obfuscatedSentence.substr(currentLength, wordLength) + " ";
        currentLength += wordLength;
    }
    cout << "Deobfuscated sentence: " << deobfuscatedSentence << endl;
}

void wordFilter() {
}

void passwordConverter() {
    string textInput, newPassword;
    cout << "Please enter your text input: ";
    cin >> textInput;

    for (char c : textInput) {
        switch (c) {
            case 'a': newPassword += '@'; break;
            case 'e': newPassword += '3'; break;
            case 'i': newPassword += '!'; break;
            case 'o': newPassword += '0'; break;
            case 'u': newPassword += '^'; break;
            default: newPassword += c;
        }
    }

    for (int i = newPassword.length() - 1; i >= 0; --i) {
        newPassword += newPassword[i];
    }

    cout << "input: " << textInput << endl;
    cout << "output: " << newPassword << endl;
}

void wordCalculator() {
}

void palindromeCounter() {
}