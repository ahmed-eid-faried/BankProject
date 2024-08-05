#include "libs.h"
#pragma once
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "model.h"
#include "libs.h"
using namespace std;



void FindClientByAccountNumber(vector<string>& vFile, string AccountNumber) {
	int Counter = 0;
	for (string& Line : vFile) {
		if (!Line.empty())
		{
			sClient Client = ConvertLineToRecord(Line, Seperator);
			if (Client.AccountNumber == AccountNumber) {
				PrintClient(Client);
				cout << endl;
				Counter++;
			}

		}
	}
	if (Counter == 0) {
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
	}
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}
void FindClient() {
	string AccountNumber = ReadString("What is your AccountNumber?\n");
	vector<string> vFile;
	DataFromFileToVector("clients.txt", vFile);
	PrintClientHeaderTable(vFile);
	FindClientByAccountNumber(vFile, AccountNumber);
	cout << endl;
	 
}


