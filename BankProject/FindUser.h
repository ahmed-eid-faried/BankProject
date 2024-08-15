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



sUser FindUserByName(vector<string>& vFile, string Name, bool AppearMessage = true) {
	int Counter = 0;
	sUser ResultUser;
	for (string& Line : vFile) {
		if (!Line.empty())
		{
			sUser User = ConvertLineToUserRecord(Line, Seperator);
			if (User.Name == Name) {
				ResultUser = User;
				if (AppearMessage) PrintUser(User);
				if (AppearMessage)	cout << endl;
				Counter++;
			}

		}
	}
	if (Counter == 0 && AppearMessage) {
		cout << "\nUser with Account Number (" << Name << ") is Not Found!";
	}
	if (AppearMessage) cout << "\n_______________________________________________________";
	if (AppearMessage) cout << "_________________________________________\n" << endl;
	return ResultUser;
}

void FindUser() {
	cout << "====================================================" << endl;
	cout << "\t\Find User\n";
	cout << "====================================================" << endl;
	string Name = ReadString("What is your Name?\n");
	vector<string> vFile;
	DataFromFileToVector(UsersFileName, vFile);
	PrintUserHeaderTable(vFile);
	FindUserByName(vFile, Name);
	cout << endl;

}
