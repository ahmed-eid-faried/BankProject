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
void PrintUserHeaderTable(vector<string> vFile) {
	cout << "\n\t\t\t\t\tUser List (" << vFile.size() << ") User(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Name";
	cout << "| " << left << setw(10) << "Password";
	cout << "| " << left << setw(40) << "Permsions";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
};
void PrintUser(sUser User) {
	cout << "| " << setw(15) << left << User.Name;
	cout << "| " << setw(10) << left << User.Password;
	cout << "| " << setw(40) << left << User.Permsions;
};
void ReadFileByVectorUsers(vector<string>& vFile) {
	for (string& Line : vFile) {
		if (!Line.empty())
		{
			sUser User = ConvertLineToUserRecord(Line, Seperator);
			PrintUser(User);
			cout << endl;
		}
	}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void ListUsers() {
	vector<string> vFile;
	DataFromFileToVector(UsersFileName, vFile);
	PrintUserHeaderTable(vFile);
	ReadFileByVectorUsers(vFile);
	cout << endl;

}
