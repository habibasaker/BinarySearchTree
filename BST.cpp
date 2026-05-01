//hanya essam eldin mohamed--20246122
//habiba amr mohamed--20246042
#include<string>
#include <iostream>
#include "BST.h"
#include <fstream>
using namespace std;

int main() {
    BST tree;
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Error: Could not open input.txt" << endl;
        return 1;
    }
    int numAppointment;

    inputFile >> numAppointment;
    inputFile.ignore();

    for (int i = 0; i < numAppointment; i++) {
        string name, department;
        int    priorityLevel;

        getline(inputFile, name);
        inputFile >> priorityLevel;
        inputFile.ignore();
        getline(inputFile, department);

        tree.scheduleAppointment(name, priorityLevel, department);
    }

    inputFile.close();
    cout <<numAppointment << " appointments loaded successfully." << endl;


    int choice;
    do {
        cout << "\n1. Schedule an appointment " << endl;
        cout << "2. Display all appointments " << endl;
        cout << "3. Search for an appointment " << endl;
        cout << "4. Cancel an appointment " << endl;
        cout << "5. Display more urgent than " << endl;
        cout << "6. Display less urgent than " << endl;
        cout << "0. Exit" << endl;
        cout << "Enter number of option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name, department;
            int priorityLevel;

            cout << "Enter patient name: ";
            getline(cin, name);
            cout << "Enter priority level: ";
            cin >> priorityLevel;
            cin.ignore();
            cout << "Enter department: ";
            getline(cin, department);

            tree.scheduleAppointment(name, priorityLevel, department);
            cout << "Appointment scheduled." << endl;

        }
        else if (choice == 2) {
            cout << endl;
            tree.displayAll();

        }

        else if (choice == 3) {
            int priorityLevel;
            cout << "Enter the priority level: ";
            cin >> priorityLevel;
            cout << endl;
            tree.search(priorityLevel);

        }

        else if (choice == 4) {
            int priorityLevel;
            cout << "Enter the priority level: ";
            cin >> priorityLevel;
            cout << endl;
            tree.cancelAppointment(priorityLevel);

        }
        else if (choice == 5) {
            int priorityLevel;
            cout << "Display more urgent than: ";
            cin >> priorityLevel;
            cout << endl;
            tree.displayMoreUrgentThan(priorityLevel);

        }
        else if (choice == 6) {
            int priorityLevel;
            cout << "Display less urgent than: ";
            cin >> priorityLevel;
            cout << endl;
            tree.displayLessUrgentThan(priorityLevel);

        }

        else if (choice == 0) {
            cout << "Exit successfully" << endl;
        }

        else {
            cout << "Invalid option. Please try again." << endl;
        }

    } while (choice != 0);
    
    return 0;}
