#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip> // for formatting
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
    string email;
    string phone;
};

vector<Person> people;

// Load from file
void loadFromFile() {
    ifstream in("people.txt");
    string line;

    while (getline(in, line)) {
        stringstream ss(line);
        Person p;
        string ageStr;

        getline(ss, p.name, '|');
        getline(ss, ageStr, '|');
        p.age = stoi(ageStr);
        getline(ss, p.email, '|');
        getline(ss, p.phone, '|');

        people.push_back(p);
    }

    in.close();
    cout << "Loaded " << people.size() << " record(s) from file.\n";
}

// Add a new person
void addPerson() {
    Person p;
    cout << "Enter full name: ";
    getline(cin, p.name);
    cout << "Enter age: ";
    cin >> p.age;
    cin.ignore();
    cout << "Enter email: ";
    getline(cin, p.email);
    cout << "Enter phone number: ";
    getline(cin, p.phone);

    people.push_back(p);
    cout << "✅ Person added!\n";
}

// Display all people
void viewPeople() {
    if (people.empty()) {
        cout << "No records found.\n";
        return;
    }

    cout << left << setw(20) << "Name" << setw(6) << "Age" 
         << setw(25) << "Email" << setw(15) << "Phone" << "\n";
    cout << string(70, '-') << "\n";

    for (const auto& p : people) {
        cout << left << setw(20) << p.name << setw(6) << p.age
             << setw(25) << p.email << setw(15) << p.phone << "\n";
    }
}

// Search by name
void searchPerson() {
    string keyword;
    cout << "Enter name to search: ";
    getline(cin, keyword);
    bool found = false;

    for (const auto& p : people) {
        if (p.name.find(keyword) != string::npos) {
            cout << "\nFound: \n";
            cout << "Name: " << p.name << "\nAge: " << p.age
                 << "\nEmail: " << p.email << "\nPhone: " << p.phone << "\n";
            found = true;
        }
    }

    if (!found) cout << "No match found.\n";
}

// Save to file
void saveToFile() {
    ofstream out("people.txt");
    for (const auto& p : people) {
        out << p.name << "|" << p.age << "|" << p.email << "|" << p.phone << "\n";
    }
    out.close();
    cout << "✅ Data saved to people.txt\n";
}

int main() {
    loadFromFile(); // Load when starting
    int choice;

    while (true) {
        cout << "\n--- InfoCollector Menu ---\n";
        cout << "1. Add Person\n2. View All\n3. Search\n4. Save to File\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addPerson(); break;
            case 2: viewPeople(); break;
            case 3: searchPerson(); break;
            case 4: saveToFile(); break;
            case 5: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid option.\n";
        }
    }
}
// This program allows you to add, view, search, and save personal information to a file.
// It uses a simple text file format to store the data, making it easy to read and write.
// The program is structured to be user-friendly, with clear prompts and feedback for each action.
// The use of vectors allows for dynamic storage of records, and the program can handle multiple entries efficiently.
// The formatting of the output is done using the iomanip library, ensuring a clean and organized display of information.
// The program is designed to be extensible, allowing for future enhancements such as data validation, error handling, and more complex data structures if needed.
// The use of functions for each operation keeps the code organized and easy to maintain.
// The program is a good starting point for anyone looking to manage personal information in a simple and effective way.
// It can be further improved by adding features like data validation, error handling, and a more sophisticated user interface.
// The program is a simple yet effective way to manage personal information, making it a useful tool for anyone looking to keep track of their contacts and details.
// The program is designed to be user-friendly, with clear prompts and feedback for each action.