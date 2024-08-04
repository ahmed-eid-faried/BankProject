#include <iostream>
#include <string>
#include "1.h"
#include "2.h"
#include "3.h"
#include "4.h"
#include "5.h"
using namespace std;
int ReadNumberInRange(int From, int To, string Message = "ENTER NUMBER") {
	int NUM;
	do {
		cout << Message << " FROM " << to_string(From) << " TO " << to_string(To) << ": ";
		cin >> NUM;
	} while (NUM < From || NUM > To);
	return NUM;
}
void Routing(short Num) {
	switch (Num)
	{
	case 1:
		system("cls");
		ShowClients();
	case 2:
		system("cls");
		AddNewClient();
	case 3:
		system("cls");
		DeleteClient();
	case 4:
		system("cls");
		UpdateClientInfo();
	case 5:
		system("cls");
		FindClient();
	case 6:
		cout << "Exiting the CLI" << endl;
		exit(0);
	default:
		break;
	}
}

int main()
{
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
	short Num = ReadNumberInRange(1, 6, "Choose what do you want to do? [1 to 6]? ");
	Routing(Num);
}
