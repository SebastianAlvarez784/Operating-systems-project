#include <iostream>

using namespace std;

// Declare the function 
bool authenticateUser();

int main() {
    cout << "OS is booting up..." << endl;

    if (authenticateUser()) {
        cout << "Login succesful" << endl;
    } else {
        cout << "Access denied." << endl;
    }

    return 0;
}
