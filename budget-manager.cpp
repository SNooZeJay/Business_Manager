// budget-manager.cpp
#include <iostream>
#include "../header2.h"

using namespace std;

// constructor: initializes expense count and saving goal
Budget::Budget() {
    expenseCount = 0;
    savingGoal = 0;
}

// add a new expense
void Budget::addExpense(string name, double amount) {
    if (expenseCount < MAX_EXPENSES) {
        expenses[expenseCount].name = name;
        expenses[expenseCount].amount = amount;
        expenseCount++;
        cout << "Expense added.\n";
    } else {
        cout << "Maximum expenses reached.\n";
    }
}

// edit an existing expense
void Budget::editExpense(int index, string name, double amount) {
    if (index >= 0 && index < expenseCount) {
        expenses[index].name = name;
        expenses[index].amount = amount;
        cout << "Expense updated.\n";
    } else {
        cout << "Invalid input, please try again.\n";
    }
}

// delete an expense
void Budget::deleteExpense(int index) {
    if (index >= 0 && index < expenseCount) {
        for (int i = index; i < expenseCount - 1; i++) {
            expenses[i] = expenses[i + 1];
        }
        expenseCount--;
        cout << "Expense deleted.\n";
    } else {
        cout << "Invalid input, please try again.\n";
    }
}

// display all expenses
void Budget::displayExpenses() {
    cout << "\n ==== Expenses ==== \n";
    for (int i = 0; i < expenseCount; i++) {
        cout << i + 1 << ". " << expenses[i].name << ": " << expenses[i].amount << endl;
    }
    cout << "\n Total Expenses: " << getTotal() << endl;
}

// calculate total expenses
double Budget::getTotal() {
    double total = 0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// set the saving goal
void Budget::setSavingGoal(double goal) {
    savingGoal = goal;
    cout << "Saving goal set to " << savingGoal << endl;
}

// check savings status
void Budget::checkSavings() {
    double remaining = savingGoal - getTotal();
    if (savingGoal == 0) {
        cout << "No saving goal set.\n";
    } else if (remaining > 0) {
        cout << "You are within your saving goal. You can still spend " << remaining << endl;
    } else if (remaining == 0) {
        cout << "You have exactly met your saving goal.\n";
    } else {
        cout << "You have exceeded your saving goal by " << -remaining << endl;
    }
}

// delete the saving goal
void Budget::deleteSavingGoal() {
    if (savingGoal == 0) {
        cout << "No saving goal to delete.\n";
    } else {
        savingGoal = 0;
        cout << "Saving goal deleted.\n";
    }
}
