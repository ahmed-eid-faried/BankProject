#pragma once
#include "1.h"
#include "2.h"
#include "3.h"
#include "4.h"
#include "5.h"
#include "libs.h"
#include "6.h"
#include "7.h"
using namespace std;
void LoginScreen();
enum enMainMenueOptions {
	eShowClients = 1,
	eAddNewClient = 2,
	eDeleteClient = 3,
	eUpdateClientInfo = 4,
	eFindClient = 5,
	eTransactions = 6,
	eMangeUsers = 7,
	eExiting = 8,
};
int ReadNumberInRange(int From, int To, string Message = "ENTER NUMBER") {
	int NUM;
	do {
		cout << Message << " FROM " << to_string(From) << " TO " << to_string(To) << ": ";
		cin >> NUM;
	} while (NUM < From || NUM > To);
	return NUM;
}
void Routing(enMainMenueOptions Option) {
	switch (Option)
	{
	case enMainMenueOptions::eShowClients:
		system("cls");
		ShowClients();
		BackToMainMenue();
	case enMainMenueOptions::eAddNewClient:
		system("cls");
		AddNewClient();
		BackToMainMenue();
	case enMainMenueOptions::eDeleteClient:
		system("cls");
		DeleteClient();
		BackToMainMenue();
	case enMainMenueOptions::eUpdateClientInfo:
		system("cls");
		UpdateClientInfo();
		BackToMainMenue();
	case enMainMenueOptions::eFindClient:
		system("cls");
		FindClient();
		BackToMainMenue();

	case enMainMenueOptions::eTransactions:
		system("cls");
		checkPermission(enPermissions::PERMISSION_Find) ? Transactions() : DeniedPermissions();
		BackToMainMenue();

	case enMainMenueOptions::eMangeUsers:
		system("cls");
		MangeUsers();
		BackToMainMenue();


	case enMainMenueOptions::eExiting:
		system("cls");
		LoginScreen();
		//Exiting();
	default:
		break;
	}
}
void ShowMainMenue() {
	cout << "====================================================" << endl;
	cout << "\t\tMain Menue Screen\n";
	cout << "====================================================" << endl;
	cout << "\t   [1] Show Client List." << endl;
	cout << "\t   [2] Add New Client." << endl;
	cout << "\t   [3] Delete Client." << endl;
	cout << "\t   [4] Update Client info." << endl;
	cout << "\t   [5] Find Client." << endl;
	cout << "\t   [6] Transactions Menue." << endl;
	cout << "\t   [7] Mange Users Menue." << endl;
	cout << "\t   [8] Logout." << endl;
	cout << "====================================================" << endl;
	enMainMenueOptions Option = (enMainMenueOptions)ReadNumberInRange(1, 8, "Choose what do you want to do? [1 to 8]? ");
	Routing(Option);
}