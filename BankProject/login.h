#pragma once
#include <iostream>
#include "libs.h"
using namespace std;
sUser KFindUser(vector<string>& vFile, string Name) {
	int Counter = 0;
	sUser ResultUser;
	for (string& Line : vFile) {
		if (!Line.empty())
		{
			sUser User = ConvertLineToUserRecord(Line, Seperator);
			if (User.Name == Name) {
				ResultUser = User;
 				Counter++;
			}
		}
	}
	if (Counter == 0) {
		cout << "\nUser with Account Number (" << Name << ") is Not Found!";
	}
	return ResultUser;
}

bool CheckPassword(string Name, string Password) {
	vector<string> vFile;
	DataFromFileToVector(UsersFileName, vFile);
 	sUser User = KFindUser(vFile, Name);
	bool state = User.Name == Name;
	if (state)CurrentUser = User;
	return state;
}

void Login() {
	bool IsFinsh = false;
	while (!IsFinsh)
	{
		string Name = ReadString("Enter your Name    : ");
		string Password = ReadString("Enter your Password: ");
		if (CheckPassword(Name, Password)) {
			IsFinsh = true; 
		}
	}
	system("cls");
	ShowMainMenue();
}
void LoginScreen() {
	cout << "========================================================" << endl;
	cout << "                         Login                          " << endl;
	cout << "========================================================" << endl;
	Login();
	cout << "========================================================" << endl;
	cout << "========================================================" << endl;
}