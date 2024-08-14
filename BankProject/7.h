#pragma once
#include <iostream>
#include "ListUsers.h"
#include "AddNewUser.h"
#include "DeleteUser.h"
#include "UpdateUser.h"
#include "FindUser.h"
using namespace std;
enum enMangeUsersMenueOptions {
	eListUsers = 1,
	eAddNewUser = 2,
	eDeleteUser = 3,
	eUpdateUser = 4,
	eFindUser = 5,
	enMainMenue = 6,
};
void ShowMangeUsersMenue();
void BackToMangeUsersMenue() {
	cout << "Press any key to go back to Main Menu...";
	cin.ignore(); // Clear the input buffer
	cin.get();    // Wait for a key press
	system("cls"); // Clear the screen
	//system("pause>0");
	ShowMangeUsersMenue();
}
void RoutingMangeUsers(enMangeUsersMenueOptions Option) {
	switch (Option)
	{
	case enMangeUsersMenueOptions::eListUsers:
		system("cls");
		checkPermission(enPermissions::PERMISSION_ListUsers) ? ListUsers() : DeniedPermissions();
		BackToMangeUsersMenue();
	case enMangeUsersMenueOptions::eAddNewUser:
		system("cls");
		AddNewUser();
		checkPermission(enPermissions::PERMISSION_Add) ? AddNewUser() : DeniedPermissions();
		BackToMangeUsersMenue();
	case enMangeUsersMenueOptions::eDeleteUser:
		system("cls");
		checkPermission(enPermissions::PERMISSION_Delete) ? DeleteUser() : DeniedPermissions();
		BackToMangeUsersMenue();
	case enMangeUsersMenueOptions::eUpdateUser:
		system("cls");
		checkPermission(enPermissions::PERMISSION_Update) ? UpdateUser() : DeniedPermissions();
		BackToMangeUsersMenue();
	case enMangeUsersMenueOptions::eFindUser:
		system("cls");
		checkPermission(enPermissions::PERMISSION_Find) ? FindUser() : DeniedPermissions();
		BackToMangeUsersMenue();
	case enMangeUsersMenueOptions::enMainMenue:
		system("cls");
		ShowMainMenue();
	default:
		break;
	}
}

void ShowMangeUsersMenue() {
	cout << "====================================================" << endl;
	cout << "\t\MangeUsers Menue Screen\n";
	cout << "====================================================" << endl;
	cout << "\t   [1] List Users." << endl;
	cout << "\t   [2] Add New User." << endl;
	cout << "\t   [3] Delete User." << endl;
	cout << "\t   [4] Update User." << endl;
	cout << "\t   [5] Find User." << endl;
	cout << "\t   [6] Main Menue." << endl;
	cout << "====================================================" << endl;
	enMangeUsersMenueOptions Option = (enMangeUsersMenueOptions)ReadNumberInRange(1, 6, "Choose what do you want to do? [1 to 6]? ");
	RoutingMangeUsers(Option);
}


void MangeUsers() {
	ShowMangeUsersMenue();
}