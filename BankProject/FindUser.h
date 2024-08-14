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



void FindUserByName(vector<string>& vFile, string Name) {
	int Counter = 0;
	for (string& Line : vFile) {
		if (!Line.empty())
		{
			sUser User = ConvertLineToUserRecord(Line, Seperator);
			if (User.Name == Name) {
				PrintUser(User);
				cout << endl;
				Counter++;
			}

		}
	}
	if (Counter == 0) {
		cout << "\nUser with Account Number (" << Name << ") is Not Found!";
	}
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
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
 