#pragma once
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include<fstream>
#include "libs.h"
#include "Permsions.h"
using namespace std;

sUser FindUserByName(vector<string>& vFile, string Name, bool AppearMessage);
bool IsFindUserByName(string Name) {
	vector<string> vFile;
	DataFromFileToVector(UsersFileName, vFile);
	sUser User = FindUserByName(vFile, Name, false);
	bool state = User.Name == Name;
	return state;
}
sUser ReadNewUser() {
	sUser user;
	user.Name = ReadString("ENTER YOUR Name: ");
	user.Password = ReadString("ENTER YOUR Password: ");
	bool State = ReadBool("ARE YOU ENTER Permissions ?");
	user.Permissions = State ? ReadPermissions() : 0;
	return user;
};
void AddUser() {
	cout << "\nPlease Enter User Data:  " << endl;
	sUser User;
	User = ReadNewUser();
	if (IsFindUserByName(User.Name)) {
		cout << "\n\nUser already exists.\n";
	}
	cout << "\n\nUser Record for Saving is: \n";
	string Line = ConvertRecordToLineUser(User, Seperator);
	cout << Line << endl;
	AddDataToFile(UsersFileName, Line);
}
void AddUsers() {
	char AddMore = 'Y';
	do
	{
		system("cls");
		cout << "====================================================" << endl;
		cout << "\t\tAdd New User\n";
		cout << "====================================================" << endl;
		AddUser();
		cout << "\nUser Added Successfully, do you want to add more users? Y/N? ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}
void AddNewUser() {
	AddUsers();
	cout << endl;
}


