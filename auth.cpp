#include <iostream>
#include <string>
#include "auth.h"

using namespace std;


bool authenticateUser() {
    string username, password;
    const string correctUsername = "Username";  
    const string correctPassword = "Password2025";  

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    if (username == correctUsername && password == correctPassword) {
        return true;
    } else {
        return false;
    }
}
