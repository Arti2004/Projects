#include<iostream>
#include<fstream>
using namespace std;

class temp {

    string id, name, author, search;
    fstream file;
    public:
    void addBook();
    void showAll();
    void extractBook();

} obj;

int main() {

    char choice;
    while (true) {
        cout << "----------------------------------" << endl;
        cout << "1 - Show All Books" << endl;
        cout << "2 - Extract Book" << endl;
        cout << "3 - Add books (ADMIN)" << endl;
        cout << "4 - Exit" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter Your Choice :: ";
        cin >> choice;

        cin.ignore();  // to clear the buffer

        switch (choice) {
            case '1':
                obj.showAll();
                break;
            case '2':
                obj.extractBook();
                break;
            case '3':
                obj.addBook();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid Choice...!" << endl;
        }
    }

    return 0;
}

void temp::addBook() {
    cout << "\nEnter Book ID :: ";
    getline(cin, id);
    cout << "Enter Book Name :: ";
    getline(cin, name);
    cout << "Enter Book's Author name :: ";
    getline(cin, author);

    file.open("bookData.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << id << "*" << name << "*" << author << endl;
        file.close();
        cout << "Book added successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

void temp::showAll() {
    file.open("bookData.txt", ios::in);
    if (file.is_open()) {
        cout << "\n\n";
        cout << "\t\t Book Id \t\t\t Book Name \t\t\t Author's Name" << endl;
        while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n')) {
            cout << "\t\t " << id << " \t\t\t\t " << name << " \t\t\t " << author << endl;
        }
        file.close();
    } else {
        cout << "Error opening file or file does not exist!" << endl;
    }
}

void temp::extractBook() {
    showAll();
    cout << "Enter Book Id :: ";
    getline(cin, search);

    bool found = false;
    file.open("bookData.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n')) {
            if (search == id) {
                cout << "\n\n";
                cout << "\t\t Book Id \t\t\t Book Name \t\t\t Author's Name" << endl;
                cout << "\t\t " << id << " \t\t\t " << name << " \t\t\t " << author << endl;
                cout << "Book Extracted Successfully...!" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book with ID " << search << " not found!" << endl;
        }
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}