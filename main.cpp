#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    fstream f1, temp, f2;
    f1.open("/home/pt/CLionProjects/LR7/f1.txt", ios::in);
    temp.open("/home/pt/CLionProjects/LR7/temp.txt", ios::out);
    if (!f1) {
        cout << "File not found";
        return 0;
    }
    char c;
    bool wasSpace = true;
    while (f1.get(c)) {
        if (c == ' ') {
            if (!wasSpace) {
                temp << c;
            }
            wasSpace = true;
        } else if (c == '.' || c == ',' || c == '?' || c == ';') {
            temp << ' ';
            wasSpace = true;
        } else {
            if (wasSpace) {
                c = toupper(c);
            }
            temp << c;
            wasSpace = false;
        }
    }

    f1.close();
    temp.close();
    temp.open("/home/pt/CLionProjects/LR7/temp.txt", ios::in);
    f2.open("/home/pt/CLionProjects/LR7/f2.txt", ios::out);
    string word;
    while (temp >> word) {
        f2 << word << " ";
    }
    temp.close();

    return 0;
}
