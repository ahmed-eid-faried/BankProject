#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "model.h"
#include "libs.h"


using namespace std;
void PrintClientHeaderTable(vector<string> vFile) {
	cout << "\n\t\t\t\t\tClient List (" << vFile.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
};
void PrintClient(sClient Client) {
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
};
void ReadFileByVector(vector<string>& vFile) {
	for (string& Line : vFile) {
		if (!Line.empty())
		{
			sClient Client = ConvertLineToRecord(Line, Seperator);
			PrintClient(Client);
			cout << endl;
		}
	}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void ShowClients() {
	vector<string> vFile;
	DataFromFileToVector(ClientsFileName, vFile);
	PrintClientHeaderTable(vFile);
	ReadFileByVector(vFile);
	cout << endl;
	 
}