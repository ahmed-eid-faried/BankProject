#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "model.h"
#include "libs.h"


using namespace std;
void PrintClientHeaderTotalBalances(vector<string> vFile) {
	cout << "\n\t\t\t\t\tClient List (" << vFile.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
};
void PrintClientTotalBalances(sClient Client) {
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.AccountBalance;
};
void ReadFileByVectorTotalBalances(vector<string>& vFile, double& TotalBalances) {
	TotalBalances = 0;
	for (string& Line : vFile) {
		if (!Line.empty())
		{
			sClient Client = ConvertLineToRecord(Line, Seperator);
			TotalBalances += Client.AccountBalance;
			PrintClientTotalBalances(Client);
			cout << endl;
		}
	}
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void TotalBalances() {
	vector<string> vFile;
	double TotalBalances = 0;
	DataFromFileToVector(ClientsFileName, vFile);
	PrintClientHeaderTotalBalances(vFile);
	ReadFileByVectorTotalBalances(vFile, TotalBalances);
	cout << "\t\t\t\t\tTotal Balances = " << TotalBalances << endl;
	cout << endl;
}