#include <iostream>
#include <string>

using namespace std;

bool authenticateUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Hardcoded credentials
    if (username == "username" && password == "password") {
        cout << "Login successful!" << endl;
        return true;
    } else {
        cout << "Try again." << endl;
        return false;
    }
}

