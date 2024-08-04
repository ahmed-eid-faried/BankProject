#pragma once
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include<fstream>
using namespace std;

sClient ReadNewClient() {
	sClient client;
	client.AccountNumber = ReadString("ENTER YOUR AccountNumber: ");
	client.PinCode = ReadString("ENTER YOUR PinCode: ");
	client.Name = ReadString("ENTER YOUR Name: ");
	client.Phone = ReadString("ENTER YOUR Phone: ");
	client.AccountBalance = ReadDoubleNumber("ENTER YOUR AccountBalance: ");
	return client;
};
void AddClient() {
	cout << "\nPlease Enter Client Data:  " << endl;
	sClient Client;
	Client = ReadNewClient();
	cout << "\n\nClient Record for Saving is: \n";
	string Line = ConvertRecordToLine(Client, Seperator);
	cout << Line << endl;
	AddDataToFile(ClientsFileName, Line);
}
void AddClients() {
	char AddMore = 'Y';
	do
	{
		system("cls");
		cout << "Adding New Client: " << endl;
		AddClient();
		cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}
void AddNewClient() {
	AddClients();
	cout << endl;
	pop();
}


