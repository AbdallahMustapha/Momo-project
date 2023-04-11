#include <iostream>

using namespace std;

// Constants
const int MAX_PIN_ATTEMPTS = 3;
const string DEFAULT_PIN = "0000";
const double DEFAULT_BALANCE = 1000.0;

// Function prototypes
void showMenu();
void authenticateUser(string& pin, bool& authenticated, int& pinAttempts);
void resetPin(string& pin);
void checkBalance(double balance);
void sendMoney(double& balance);

int main() {
    string pin = DEFAULT_PIN;
    double balance = DEFAULT_BALANCE;
    bool authenticated = false;
    int pinAttempts = 0;
    int choice;

    // Loop until exit option is selected
    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: // Authenticate
                authenticateUser(pin, authenticated, pinAttempts);
                break;
            case 2: // Reset PIN
                if (authenticated) {
                    resetPin(pin);
                } else {
                    cout << "You need to authenticate first.\n";
                }
                break;
            case 3: // Check balance
                if (authenticated) {
                    checkBalance(balance);
                } else {
                    cout << "You need to authenticate first.\n";
                }
                break;
            case 4: // Send money
                if (authenticated) {
                    sendMoney(balance);
                } else {
                    cout << "You need to authenticate first.\n";
                }
                break;
            case 5: // Exit
                cout << "Thank you for using the Mobile Money Service. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}

// Function definitions

// Displays the main menu
void showMenu() {
    cout << "==============================\n";
    cout << "Mobile Money Service\n";
    cout << "==============================\n";
    cout << "1. Authenticate\n";
    cout << "2. Reset PIN\n";
    cout << "3. Check balance\n";
    cout << "4. Send money\n";
    cout << "5. Exit\n";
    cout << "==============================\n";
    cout << "Enter your choice: ";
}

// Authenticates the user by comparing entered PIN with the default PIN
void authenticateUser(string& pin, bool& authenticated, int& pinAttempts) {
    string enteredPin;
    cout << "Enter PIN: ";
    cin >> enteredPin;

    if (enteredPin == pin) {
        authenticated = true;
        pinAttempts = 0;
        cout << "Authentication successful.\n";
    } else {
        pinAttempts++;
        if (pinAttempts >= MAX_PIN_ATTEMPTS) {
            cout << "Too many incorrect PIN attempts. Exiting...\n";
            exit(0);
        } else {
            cout << "Incorrect PIN. Please try again.\n";
        }
    }
}

// Resets the PIN
void resetPin(string& pin) {
    string newPin;
    cout << "Enter new PIN: ";
    cin >> newPin;
    pin = newPin;
    cout << "PIN reset successful.\n";
}

// Checks and displays the current balance
void checkBalance(double balance) {
    cout << "Current balance: $" << balance << endl;
}

// Sends money and updates the balance
void sendMoney(double& balance) {
    double amount;
    cout << "Transfer money: " << endl;
}
