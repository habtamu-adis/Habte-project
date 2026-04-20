#include <iostream>
using namespace std;
class BankAccount {
private:
string accountNumber;
string password;
string name;
double balance;
public:
void createAccount() {
cout << "Enter Account Number: ";
cin >> accountNumber;
cout << "Enter Password: ";
cin >> password;cout << "Enter Name: ";
cin.ignore();
getline(cin, name);
cout << "Enter Initial Balance: $";
cin >> balance;
cout << "\nAccount Created Successfully!\n";
}
bool authenticate() {
string accNum, pass;
cout << "Enter Account Number: ";
cin >> accNum;
cout << "Enter Password: ";
cin >> pass;
if (accNum == accountNumber && pass == password) {
return true;
} else {
cout << "Invalid credentials!\n";
return false;
}
}void deposit() {
if (!authenticate()) return;
double amount;
cout << "Enter amount to deposit: $";
cin >> amount;
if (amount > 0) {
balance += amount;
cout << "Deposit successful! New balance: $" << balance
<< endl;
} else {
cout << "Invalid amount!\n";
}
}
void withdraw() {
if (!authenticate()) return;
double amount;
cout << "Enter amount to withdraw: $";
cin >> amount;
if (amount > 0 && amount <= balance) {balance -= amount;
cout << "Withdrawal successful! New balance: $" <<
balance << endl;
} else if (amount > balance) {
cout << "Insufficient balance!\n";
} else {
cout << "Invalid amount!\n";
}
}
void checkBalance() {
if (!authenticate()) return;
cout << "\nAccount Holder: " << name << endl;
cout << "Account Number: " << accountNumber << endl;
cout << "Current Balance: $" << balance << endl;
}
};
int main() {
BankAccount account;
int choice;
cout << "BANK ACCOUNT MANAGEMENT SYSTEM \n";while (true) {
cout << "\n1. Create Account\n";
cout << "2. Deposit Money\n";
cout << "3. Withdraw Money\n";
cout << "4. Check Balance\n";
cout << "5. Exit\n";
cout << "Enter your choice (1-5): ";
cin >> choice;
switch (choice) {
case 1:
account.createAccount();
break;
case 2:
account.deposit();
break;
case 3:
account.withdraw();
break;
case 4:
account.checkBalance();break;
case 5:
cout << "Thank you for using our banking system!\n";
return 0;
default:
cout << "Invalid choice! Please try again.\n";
}
}
return 0;
}