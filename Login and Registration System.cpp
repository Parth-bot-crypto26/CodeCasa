#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser(const string& username, const string& password) {
    ofstream userFile("users.txt", ios::app);

    if (userFile.is_open()) {
        userFile<<username<<" "<<password<<endl;
        userFile.close();
        cout<<"User registered successfully."<<endl;
    } else {
        cerr<<"Error: Unable to open user file for registration."<<endl;
    }
}

bool userExists(const string& username, const string& password) {
    ifstream userFile("users.txt");
    if (userFile.is_open()) {
        string storedUsername, storedPassword;
        while (userFile>>storedUsername>>storedPassword) {
            if (username == storedUsername && password == storedPassword) {
                userFile.close();
                return true;
            }
        }
        userFile.close();
    }
    return false;
}

int main() {
    string username, password;
    char choice;

    cout<<"Welcome to User Registration and Login System"<<endl;

    do {
        cout<<"\nMenu:\n";
        cout<<"1. Register a new user\n";
        cout<<"2. Login\n";
        cout<<"3. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case '1':
                cout<<"Enter a new username: ";
                cin>>username;
                cout<<"Enter a password: ";
                cin>>password;
                registerUser(username, password);
                break;

            case '2':
                cout<<"Enter your username: ";
                cin>>username;
                cout<<"Enter your password: ";
                cin>>password;

                if (userExists(username, password)) {
                    cout<<"Login successful. Welcome, "<<username<<"!"<<endl;
                } else {
                    cout<<"Login failed. User not found or incorrect credentials."<<endl;
                }
                break;

            case '3':
                cout<<"Goodbye!"<<endl;
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;
                break;
        }
    } while (choice != '3');

    return 0;
}
