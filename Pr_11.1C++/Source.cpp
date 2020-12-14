#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

void Create(string f1name) {
    ofstream f1out(f1name, ios::binary);
    string s;

    cin.get();
    cin.sync();
    cout << " ¬вед≥ть р€док: "; getline(cin, s);

    for (unsigned i = 0; i < s.length(); i++) {
        f1out.write((char*)&s[i], sizeof(s[i]));
    }

    cout << endl;
}

void FromF1ToF2(string f1name, string f2name) {
    ifstream f1in(f1name, ios::binary);
    ofstream f2out(f2name, ios::binary);

    char s;

    while (f1in.read((char*)&s, sizeof(s))) {
        if (s == 'A' || s == 'a' || s == 'B' || s == 'b' || s == 'C' || s == 'c' || s == 'D' || s == 'd' || s == 'E' || s == 'e' || s == 'F' || s == 'f' || s == 'G' || s == 'g' || s == 'H' || s == 'h' || s == 'I' || s == 'i' || s == 'J' || s == 'j' || s == 'K' || s == 'k' || s == 'L' || s == 'l' || s == 'M' || s == 'm' || s == 'N' || s == 'n' || s == 'O' || s == 'o' || s == 'P' || s == 'p' || s == 'Q' || s == 'q' || s == 'R' || s == 'r' || s == 'S' || s == 's' || s == 'T' || s == 't' || s == 'U' || s == 'u' || s == 'V' || s == 'v' || s == 'W' || s == 'w' || s == 'X' || s == 'x' || s == 'Y' || s == 'y' || s == 'Z' || s == 'z') {
            f2out.write((char*)&s, sizeof(s));
        }
    }
}

void PrintSecondFile(string f2name) {
    ifstream f2in(f2name, ios::binary);

    char s;

    cout << " –€док другого файлу:";

    while (f2in.read((char*)&s, sizeof(s))) {
        cout << s;
    }
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string f1name, f2name, f1namehelp, f2namehelp;
    cout << " ¬вед≥ть назву першого файлу: "; cin >> f1namehelp;
    cout << " ¬вед≥ть назву другого файлу: "; cin >> f2namehelp;

    f1name = f1namehelp + ".txt";
    f2name = f2namehelp + ".txt";

    Create(f1name);
    FromF1ToF2(f1name, f2name);
    PrintSecondFile(f2name);
    return 0;
}