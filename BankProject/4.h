 #include<iostream>
#include<fstream>
#include<string >
#include<vector>
#include<iomanip>
using namespace std;

sClient ReadUpdateClient(string AccountNumber) {
	sClient client;
	client.AccountNumber = AccountNumber;
	client.PinCode = ReadString("ENTER YOUR PinCode: ");
	client.Name = ReadString("ENTER YOUR Name: ");
	client.Phone = ReadString("ENTER YOUR Phone: ");
	client.AccountBalance = ReadDoubleNumber("ENTER YOUR AccountBalance: ");
	return client;
};
 bool MarkClientForUpdateByAccountNumber(string AccountNumber, vector <sClient>& vClients) {
	for (sClient& C : vClients) {
		if (C.AccountNumber == AccountNumber) {
			C.MarkForUpdate = true;
			return true;
		}
	} return false;
}
vector <sClient> SaveUpdateCleintsDataToFile(string FileName, vector<sClient> vClients) {
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
				DataLine = ConvertRecordToLine(ReadUpdateClient(C.AccountNumber), Seperator);
				MyFile << DataLine << endl;
			}
		}         MyFile.close();
	} return vClients;
}
bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
		PrintClientCard(Client);
		cout << "\n\nAre you sure you want update this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			MarkClientForUpdateByAccountNumber(AccountNumber, vClients);
			SaveUpdateCleintsDataToFile(ClientsFileName, vClients);
			//Refresh Clients
			vClients = LoadCleintsDataFromFile(ClientsFileName);
			cout << "\n\nClient Update Successfully.";
			return true;
		}
	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}




void UpdateClientInfo() {
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, vClients);
	 
}