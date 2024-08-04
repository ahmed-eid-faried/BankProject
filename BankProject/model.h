#pragma once
#include <string>
using namespace std;
const string  ClientsFileName = "clients.txt";
const string  Seperator = "#%&#";

struct sClient {
	string  AccountNumber;
	string  PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};