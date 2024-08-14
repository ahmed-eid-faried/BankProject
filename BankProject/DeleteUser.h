#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "libs.h"

using namespace std;

bool FindUserByName(string Name, vector<sUser> vUsers, sUser& User) {
	for (sUser C : vUsers) {
		if (C.Name == Name) {
			User = C;
			return true;
		}
	}
	return false;
}
bool MarkUserForDeleteByName(string Name, vector <sUser>& vUsers) {
	for (sUser& C : vUsers) {
		if (C.Name == Name) {
			C.MarkForDelete = true;
			return true;
		}
	} return false;
}
bool DeleteUserByName(string Name, vector<sUser>& vUsers) {
	sUser User;
	char Answer = 'n';

	if (FindUserByName(Name, vUsers, User)) {
		PrintUserCard(User);
		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			MarkUserForDeleteByName(Name, vUsers);
			SaveUsersDataToFile(UsersFileName, vUsers);
			//Refresh Users
			vUsers = LoadCleintsDataFromFile(UsersFileName);
			cout << "\n\nUser Deleted Successfully.";
			return true;
		}
	}
	else {
		cout << "\nUser with Account Number (" << Name << ") is Not Found!";
		return false;
	}
}


void DeleteUser() {

	cout << "====================================================" << endl;
	cout << "\t\tDelete User\n";
	cout << "====================================================" << endl;
	vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);
	string Name = ReadString("\nPlease enter AccountNumber? ");
	DeleteUserByName(Name, vUsers);

}
 