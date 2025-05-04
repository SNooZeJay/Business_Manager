// header2.h
#ifndef HEADER2_H
#define HEADER2_H

#include <string>
using namespace std;

const int MAX_EXPENSES = 10; // max number of expenses

struct Expense {
    string name;
    double amount;
};

class Budget {
private:
    Expense expenses[MAX_EXPENSES];
    int expenseCount;
    double savingGoal;
public:
    Budget(); // constructor
    void addExpense(string name, double amount); // add a new expense
    void editExpense(int index, string name, double amount); // edit existing expense
    void deleteExpense(int index); // delete an expense
    void displayExpenses();
    double getTotal();
    void setSavingGoal(double goal); // set a saving goal
    void checkSavings(); // check savings against goal
    void deleteSavingGoal(); // delete the saving goal
};

#endif
