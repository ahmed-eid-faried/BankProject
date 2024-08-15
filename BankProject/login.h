#pragma once
#include <iostream>
#include "libs.h"
using namespace std;
bool FindUserByNameAndPassword(vector<string>& vFile, string Name, string Password) {
	for (string& Line : vFile) {
		if (!Line.empty())
		{
			sUser User = ConvertLineToUserRecord(Line, Seperator);
			if ((User.Name == Name) && (User.Password == Password)) {
				CurrentUser = User;
				return true;
			}
		}
	}
	return false;
}

bool CheckPassword(string Name, string Password) {
	vector<string> vFile;
	DataFromFileToVector(UsersFileName, vFile);
 	return FindUserByNameAndPassword(vFile, Name, Password);
}

void Login() {
	bool IsFinsh = false;
	bool Invalid = false;
	while (!IsFinsh)
	{
		system("cls");
		cout << "========================================================" << endl;
		cout << "                         Login                          " << endl;
		cout << "========================================================" << endl;
		if (Invalid) { cout << "\nUser Name Or Password is Not Correct!" << endl << endl; }
		string Name = ReadString("Enter your Name    : ");
		string Password = ReadString("Enter your Password: ");
		if (CheckPassword(Name, Password)) {
			IsFinsh = true;
		}
		else {
			Invalid = true;
		}
	};
	system("cls");
	ShowMainMenue();
}
void LoginScreen() {

	Login();
	cout << "========================================================" << endl;
	cout << "========================================================" << endl;
}