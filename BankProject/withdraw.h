#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "deposit.h"
using namespace std;

bool DepositClientByAccountNumber(string AccountNumber, vector<sClient>& vClients, double DepositValue);
bool WithdrawClientByAccountNumber(string AccountNumber, vector<sClient>& vClients, double WithdrawValue) {
	return DepositClientByAccountNumber(AccountNumber, vClients, -1 * WithdrawValue);
}
void WithdrawFun() {
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	double WithdrawValue = ReadDoubleNumber("ENTER YOUR Withdraw Value: ");
	WithdrawClientByAccountNumber(AccountNumber, vClients, WithdrawValue);
}
void Withdraw() {
	cout << "====================================================" << endl;
	cout << "\t\tWithdraw Client\n";
	cout << "====================================================" << endl;
	WithdrawFun();
}