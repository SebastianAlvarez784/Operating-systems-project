#include <iostream>
#include <string>
#include "auth.h"

using namespace std;

// Definition of authenticateUser function
bool authenticateUser() {
    string username, password;
    const string correctUsername = "Sebastian";  // Replace with your desired username
    const string correctPassword = "Sebastian18*";  // Replace with your desired password

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Check if the entered username and password match the correct ones
    if (username == correctUsername && password == correctPassword) {
        return true;
    } else {
        return false;
    }
}
