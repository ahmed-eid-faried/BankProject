#pragma once
#include<iostream>
#include<fstream>
#include<string >
#include<vector>
#include<iomanip>
#include "withdraw.h"
using namespace std;

sClient ReadDepositClient(sClient vClient, double DepositValue) {
	sClient client;
	client.AccountNumber = vClient.AccountNumber;
	client.PinCode = vClient.PinCode;
	client.Name = vClient.Name;
	client.Phone = vClient.Phone;
	bool CheckBalance = ((vClient.AccountBalance + DepositValue) >= 0);
	if (!CheckBalance) {
		cout << "Please Enter Correct Withdraw Value" << endl;
		WithdrawFun();
	}
	client.AccountBalance = CheckBalance ? vClient.AccountBalance + DepositValue : vClient.AccountBalance;
	return client;
};

vector <sClient> SaveDepositCleintsDataToFile(string FileName, vector<sClient> vClients, double DepositValue) {
	fstream MyFile;

	MyFile.open(FileName, ios::out);
	//overwrite
	string  DataLine;
	if (MyFile.is_open()) {
		for (sClient C : vClients) {
			if (C.MarkForUpdate == false) {
				//we only write records that are not marked for delete.  
				DataLine = ConvertRecordToLine(C, Seperator);
				MyFile << DataLine << endl;
			}
			else {
				DataLine = ConvertRecordToLine(ReadDepositClient(C, DepositValue), Seperator);
				MyFile << DataLine << endl;
			}
		}         MyFile.close();
	} return vClients;
}

bool DepositClientByAccountNumber(string AccountNumber, vector<sClient>& vClients, double DepositValue) {
	sClient Client;
	char Answer = 'n';
	if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
		PrintClientCard(Client);
		cout << "\n\nAre you sure you want update this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			MarkClientForUpdateByAccountNumber(AccountNumber, vClients);
			SaveDepositCleintsDataToFile(ClientsFileName, vClients, DepositValue);
			vClients = LoadCleintsDataFromFile(ClientsFileName);
			return true;
		}
	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}

void Deposit() {
	cout << "====================================================" << endl;
	cout << "\t\tDeposit Client\n";
	cout << "====================================================" << endl;
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	double DepositValue = ReadDoubleNumber("ENTER YOUR Deposit Value: ");
	DepositClientByAccountNumber(AccountNumber, vClients, DepositValue);
}