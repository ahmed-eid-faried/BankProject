#pragma once
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include<fstream>
#include "libs.h"

using namespace std;

sUser ReadNewUser() {
	sUser user;
	user.Name = ReadString("ENTER YOUR Name: ");
	user.Password = ReadString("ENTER YOUR Password: ");
	user.Permsions = ReadNumber("ENTER YOUR Permsions: ");
	return user;
};
void AddUser() {
	cout << "\nPlease Enter User Data:  " << endl;
	sUser User;
	User = ReadNewUser();
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
		cout << "====================================================" << endl;		AddUser();
		cout << "\nUser Added Successfully, do you want to add more users? Y/N? ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}
void AddNewUser() {
	AddUsers();
	cout << endl;
}


