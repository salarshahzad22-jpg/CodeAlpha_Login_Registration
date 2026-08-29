#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool usernameExists(const string& username) {
    ifstream file("users.txt");

    string savedUsername, savedPassword;

    while (file >> savedUsername >> savedPassword) {
        if (savedUsername == username) {
            return true;
        }
    }

    return false;
}

void registerUser() {
    string username, password;

    cout << "\n========== REGISTRATION ==========\n";

    cout << "Enter username: ";
    cin >> username;

    if (usernameExists(username)) {
        cout << "Username already exists! Please choose another.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);

    if (!file) {
        cout << "Error opening user file!\n";
        return;
    }

    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password;
    string savedUsername, savedPassword;

    cout << "\n============= LOGIN =============\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    if (!file) {
        cout << "No registered users found. Please register first.\n";
        return;
    }

    while (file >> savedUsername >> savedPassword) {
        if (savedUsername == username &&
            savedPassword == password) {

            cout << "\nLogin successful!\n";
            cout << "Welcome, " << username << "!\n";

            file.close();
            return;
        }
    }

    file.close();

    cout << "\nInvalid username or password!\n";
}

int main() {

    int choice;

    cout << "========================================\n";
    cout << "     LOGIN & REGISTRATION SYSTEM\n";
    cout << "========================================\n";

    while (true) {

        cout << "\n------------- MENU ----------------\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "-----------------------------------\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nThank you for using the system!\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
