// main.cpp
#include <iostream>
#include "header2.h"

using namespace std;

int main() {
    Budget myBudget;
    int choice;

    do {
        // input loop to repeat until valid input
        while (true) {
            cout << "\n ==== Budget Manager Menu ==== \n" <<endl;
            cout << "1. Add Expense\n";
            cout << "2. Edit Expense\n";
            cout << "3. Delete Expense\n";
            cout << "4. View Expenses\n";
            cout << "5. Set Saving Goal\n";
            cout << "6. Check Saving Status\n";
            cout << "7. Delete Saving Goal\n";
            cout << "0. Exit\n";
            cout << "\n Choose an option: ";
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please try again.\n";
            } else {
                break; // valid input, exit input loop
            }
        }

        if (choice == 1) {
            string name;
            double amount;
            cout << "Enter expense name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter amount: ";
            cin >> amount;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please try again.\n";
                continue;
            }
            myBudget.addExpense(name, amount);
        }
        else if (choice == 2) {
            if (myBudget.getTotal() == 0) {
                cout << "No expenses to edit.\n";
                continue;
            }
            myBudget.displayExpenses();
            int index;
            cout << "Enter expense number to edit: ";
            cin >> index;
            if (cin.fail() || index < 1 || index > MAX_EXPENSES) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please try again.\n";
                continue;
            }
            string name;
            double amount;
            cin.ignore();
            cout << "Enter new name: ";
            getline(cin, name);
            cout << "Enter new amount: ";
            cin >> amount;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please try again.\n";
                continue;
            }
            myBudget.editExpense(index - 1, name, amount);
        }
        else if (choice == 3) {
            if (myBudget.getTotal() == 0) {
                cout << "No expenses to delete.\n";
                continue;
            }
            myBudget.displayExpenses();
            int index;
            cout << "Enter expense number to delete: ";
            cin >> index;
            if (cin.fail() || index < 1 || index > MAX_EXPENSES) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please try again.\n";
                continue;
            }
            myBudget.deleteExpense(index - 1);
        }
        else if (choice == 4) {
            myBudget.displayExpenses();
        }
        else if (choice == 5) {
            double goal;
            cout << "Enter saving goal: ";
            cin >> goal;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please try again.\n";
                continue;
            }
            myBudget.setSavingGoal(goal);
        }
        else if (choice == 6) {
            myBudget.checkSavings();
        }
        else if (choice == 7) {
            myBudget.deleteSavingGoal();
        }
        else if (choice == 0) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid input, please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
