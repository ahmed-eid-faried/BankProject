#pragma once
#include<iostream>
#include<fstream>
#include<string >
#include<vector>
#include<iomanip>
using namespace std;

sUser ReadUpdateUser() {
	sUser User;
	User.Name = ReadString("ENTER YOUR Name: ");
	User.Password = ReadString("ENTER YOUR Password: ");
	User.Permissions  = ReadNumber("ENTER YOUR Permissions : ");
	return User;
};
bool MarkUserForUpdateByName(string Name, vector <sUser>& vUsers) {
	for (sUser& C : vUsers) {
		if (C.Name == Name) {
			C.MarkForUpdate = true;
			return true;
		}
	} return false;
}
vector <sUser> SaveUpdateUsersDataToFile(string FileName, vector<sUser> vUsers) {
	fstream MyFile;

	MyFile.open(FileName, ios::out);
	//overwrite
	string  DataLine;
	if (MyFile.is_open()) {
		for (sUser C : vUsers) {
			if (C.MarkForUpdate == false) {
				//we only write records that are not marked for delete.  
				DataLine = ConvertRecordToLineUser(C, Seperator);
				MyFile << DataLine << endl;
			}
			else {
				DataLine = ConvertRecordToLineUser(ReadUpdateUser(), Seperator);
				MyFile << DataLine << endl;
			}
		}         MyFile.close();
	} return vUsers;
}
bool UpdateUserByName(string Name, vector<sUser>& vUsers) {
	sUser User;
	char Answer = 'n';

	if (FindUserByName(Name, vUsers, User)) {
		PrintUserCard(User);
		cout << "\n\nAre you sure you want update this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			MarkUserForUpdateByName(Name, vUsers);
			SaveUpdateUsersDataToFile(UsersFileName, vUsers);
			//Refresh Users
			vUsers = LoadUsersDataFromFile(UsersFileName);
			cout << "\n\nUser Update Successfully.";
			return true;
		}
	}
	else {
		cout << "\nUser with Account Number (" << Name << ") is Not Found!";
		return false;
	}
}




void UpdateUser() {
	cout << "====================================================" << endl;
	cout << "\t\tUpdate User\n";
	cout << "====================================================" << endl;
	vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);
	string Name = ReadString("ENTER YOUR Name: ");
	UpdateUserByName(Name, vUsers);

}
