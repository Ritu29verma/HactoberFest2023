#include <iostream>
#include <fstream>
using namespace std;

// Function to encrypt a file using Caesar Cipher
void encryptFile(const string& inputFile, const string& outputFile, int shift) {
    ifstream fin(inputFile, ios::binary);
    ofstream fout(outputFile, ios::binary);

    if (!fin) {
        cerr << "Error: Unable to open input file." << endl;
        return;
    }

    if (!fout) {
        cerr << "Error: Unable to create output file." << endl;
        fin.close();
        return;
    }

    char ch;
    while (fin.get(ch)) {
        ch = ch + shift;
        fout.put(ch);
    }

    fin.close();
    fout.close();
    cout << "File encrypted successfully." << endl;
}

// Function to decrypt a file using Caesar Cipher
void decryptFile(const string& inputFile, const string& outputFile, int shift) {
    ifstream fin(inputFile, ios::binary);
    ofstream fout(outputFile, ios::binary);

    if (!fin) {
        cerr << "Error: Unable to open input file." << endl;
        return;
    }

    if (!fout) {
        cerr << "Error: Unable to create output file." << endl;
        fin.close();
        return;
    }

    char ch;
    while (fin.get(ch)) {
        ch = ch - shift;
        fout.put(ch);
    }

    fin.close();
    fout.close();
    cout << "File decrypted successfully." << endl;
}

int main() {
    int choice;
    cout << "Select an option:" << endl;
    cout << "1. Encrypt a file" << endl;
    cout << "2. Decrypt a file" << endl;
    cin >> choice;

    string inputFile, outputFile;
    int shift;

    if (choice == 1) {
        cout << "Enter the name of the input file: ";
        cin >> inputFile;
        cout << "Enter the name of the output file: ";
        cin >> outputFile;
        cout << "Enter the Caesar Cipher shift value: ";
        cin >> shift;
        encryptFile(inputFile, outputFile, shift);
    } else if (choice == 2) {
        cout << "Enter the name of the input file: ";
        cin >> inputFile;
        cout << "Enter the name of the output file: ";
        cin >> outputFile;
        cout << "Enter the Caesar Cipher shift value: ";
        cin >> shift;
        decryptFile(inputFile, outputFile, shift);
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
