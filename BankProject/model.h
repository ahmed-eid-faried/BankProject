#pragma once
#include <string>
using namespace std;
const string  ClientsFileName = "clients.txt";
const string  UsersFileName = "users.txt";
const string  Seperator = "#%&#";

struct sClient {
	string  AccountNumber;
	string  PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
	bool MarkForUpdate = false;
};

struct sUser {
	string  Name;
	string  Password;
	int Permissions ;
	bool MarkForDelete = false;
	bool MarkForUpdate = false;
};

struct sPermissions {
	enPermissions ListUsers = enPermissions(0);
	enPermissions Add = enPermissions(0);
	enPermissions Delete = enPermissions(0);
	enPermissions Update = enPermissions(0);
	enPermissions Find = enPermissions(0);
	enPermissions Transactions = enPermissions(0);
};