#pragma once
#include "1.h"
#include "2.h"
#include "3.h"
#include "4.h"
#include "5.h"
#include "libs.h"
#include "6.h"
#include "deposit.h"
#include "withdraw.h"
#include "total_balances.h"
using namespace std;
enum enTransactionsMenueOptions {
	eDeposit = 1,
	eWithdraw = 2,
	eTotalBalances = 3,
	eMainMenue = 4,
};
void BackToTransactionsMenue() {
	cout << "Press any key to go back to Main Menu...";
	cin.ignore(); // Clear the input buffer
	cin.get();    // Wait for a key press
	system("cls"); // Clear the screen
	//system("pause>0");
	ShowTransactionsMenue();
}
void RoutingTransactions(enTransactionsMenueOptions Option) {
	switch (Option)
	{
	case enTransactionsMenueOptions::eDeposit:
		system("cls");
		Deposit();
		BackToTransactionsMenue();
	case enTransactionsMenueOptions::eWithdraw:
		system("cls");
		Withdraw();
		BackToTransactionsMenue();
	case enTransactionsMenueOptions::eTotalBalances:
		system("cls");
		TotalBalances();
		BackToTransactionsMenue();
	case enTransactionsMenueOptions::eMainMenue:
		BackToMainMenue();
	default:
		break;
	}
}
void ShowTransactionsMenue() {
	cout << "====================================================" << endl;
	cout << "\t\tTransactions Menue Screen\n";
	cout << "====================================================" << endl;
	cout << "\t   [1] Deposit." << endl;
	cout << "\t   [2] Withdraw." << endl;
	cout << "\t   [3] Total Balances." << endl;
	cout << "\t   [4] Main Menue." << endl;
	cout << "====================================================" << endl;
	enTransactionsMenueOptions Option = (enTransactionsMenueOptions)ReadNumberInRange(1, 4, "Choose what do you want to do? [1 to 6]? ");
	RoutingTransactions(Option);
}
void Transactions() {
	ShowTransactionsMenue();
}