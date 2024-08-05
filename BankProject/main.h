#pragma once
#include "1.h"
#include "2.h"
#include "3.h"
#include "4.h"
#include "5.h"
#include "libs.h"
using namespace std;
enum enMainMenueOptions {
	eShowClients = 1,
	eAddNewClient = 2,
	eDeleteClient = 3,
	eUpdateClientInfo = 4,
	eFindClient = 5,
	eExiting = 6,
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
	switch (Num)
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
	case enMainMenueOptions::eExiting:
		cout << "Exiting the CLI" << endl;
		exit(0);
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
	cout << "\t   [6] Exit." << endl;
	cout << "====================================================" << endl;
	enMainMenueOptions Option = (enMainMenueOptions)ReadNumberInRange(1, 6, "Choose what do you want to do? [1 to 6]? ");
	Routing(Option);
}