#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool hasPunct(const string &s) {
    for (char c: s) {
        if (c == '.' || c == ',' || c == '?' || c == ';') {
            return true;
        }

    }
    return false;
}

bool wordisPunct(const string &s) {
    if (s == "." || s == "," || s == "?" || s == ";") {
        return true;
    }
    return false;
}

void processWord(string &word, fstream &f2) {
    if (hasPunct(word) && !wordisPunct(word)) {
        word.erase(word.length() - 1);
        if (word[0] == tolower(word[0])) {
            word[0] = toupper(word[0]);
            f2 << word << " ";
        } else {
            f2 << word << " ";
        }
    } else if (word[0] == tolower(word[0]) && !hasPunct(word)) {
        word[0] = toupper(word[0]);
        f2 << word << " ";
    } else if (word[0] == tolower(word[0]) && hasPunct(word) && !wordisPunct(word)) {
        word[0] = toupper(word[0]);
        word.erase(word.length() - 1);
        f2 << word << " ";

    } else if (word[0] == ',' || word[0] == '.' || word[0] == '?' || word[0] == ';') {
        word.erase(0, 1);
        f2 << word;
    } else {
        f2 << word << " ";
    }
}


int main() {
    fstream f1;
    fstream f2;
    f1.open("/home/pt/CLionProjects/LR7/f1.txt", ios::in);
    f2.open("/home/pt/CLionProjects/LR7/f2.txt", ios::out);
    if (!f1) {
        cout << "File not found!" << endl;
        return -1;
    }
    string word;
    while (f1 >> word) {
        processWord(word, f2);
    }
    f1.close();
    f2.close();
    return 0;
}

