#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "libs.h"

using namespace std;

bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client) {
	for (sClient C : vClients) {
		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}
	}
	return false;
}
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients) {
	for (sClient& C : vClients) {
		if (C.AccountNumber == AccountNumber) {
			C.MarkForDelete = true;
			return true;
		}
	} return false;
}
bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
		PrintClientCard(Client);
		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveCleintsDataToFile(ClientsFileName, vClients);
			//Refresh Clients
			vClients = LoadCleintsDataFromFile(ClientsFileName);
			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}


void DeleteClient() {
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);
	 
}