#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "model.h"

using namespace std;
bool ReadBool(string Message) {
	char AddMore = 'Y';
	cout << Message << " Y/N? " << endl;
	cin >> AddMore;
	return (toupper(AddMore) == 'Y');
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void ShowMainMenue(); // Declare ShowMainMenue here
int ReadNumberInRange(int From, int To, string Message);
void Routing(short Num);
double ReadDoubleNumber(string Message);
string ReadString(string Message);
string JoinString(vector<string> listWords, string delim);
vector<string> SplitString(string S1, string delim);
void Tabs(int num);
sClient ConvertLineToRecord(string strClientRecord, string Seperator);
void DataFromFileToVector(string path, vector<string>& vFile);
void AddDataToFile(string pathFile, string Data);
//sClient ReadUpdateClient(string AccountNumber);
string ConvertRecordToLine(sClient Client, string Seperator);
string ReadClientAccountNumber();
sClient ConvertLinetoRecord(string Line, string Seperator);
vector<sClient> LoadCleintsDataFromFile(string FileName);
void PrintClientCard(sClient Client);
vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients);
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
double ReadDoubleNumber(string Message) {
	double Num;
	cout << Message;
	cin >> Num;
	return Num;
}
int ReadNumber(string Message) {
	int Num;
	cout << Message;
	cin >> Num;
	return Num;
}
string ReadString(string Message) {
	string Text;
	cout << Message;
	getline(cin >> ws, Text);
	return Text;
}

string  JoinString(vector<string> listWords, string delim = " ") {
	string S1 = "";
	for (string i : listWords)
	{
		S1 += i + delim;
	}
	return S1.substr(0, S1.length() - (delim.length()));
};
vector<string> SplitString(string S1, string delim = " ") {

	int position = 0;
	string subWord = "";
	int counter = 0;
	vector<string> listWords;
	while ((position = S1.find(delim)) != string::npos)
	{
		subWord = S1.substr(0, position);
		if (subWord != "") listWords.push_back(subWord);
		S1.erase(0, position + delim.length());
	}
	//last word in string
	if (S1 != "")listWords.push_back(S1);
	return listWords;
}
void Tabs(int num) {
	for (int i = 0; i < num; i++)
	{
		cout << '\t';
	}
}
sClient ConvertLineToRecord(string strClientRecord, string Seperator) {
	vector<string> sListOfRecord = SplitString(strClientRecord, Seperator);
	sClient Client;
	Client.AccountNumber = sListOfRecord[0];
	Client.PinCode = sListOfRecord[1];
	Client.Name = sListOfRecord[2];
	Client.Phone = sListOfRecord[3];
	Client.AccountBalance = stod(sListOfRecord[4]);
	return Client;
}
sUser ConvertLineToUserRecord(string strUserRecord, string Seperator) {
	vector<string> sListOfRecord = SplitString(strUserRecord, Seperator);
	sUser User;
	User.Name = sListOfRecord[0];
	User.Password = sListOfRecord[1];
	User.Permissions = stoi(sListOfRecord[2]);
	return User;
}

void DataFromFileToVector(string path, vector<string>& vFile) {
	fstream MyFile;
	MyFile.open(path, ios::in);//read Mode  
	if (MyFile.is_open()) {
		string Line;
		while (getline(MyFile, Line))
		{
			vFile.push_back(Line);
		}
		MyFile.close();
	}
}
void AddDataToFile(string pathFile, string Data) {
	fstream MyFile;
	MyFile.open(pathFile, ios::out | ios::app);
	if (MyFile.is_open()) {
		MyFile << Data << endl;
		MyFile.close();
	}
}

string ConvertRecordToLine(sClient Client, string Seperator) {
	string strClientRecord = "";
	strClientRecord += Client.AccountNumber + Seperator;
	strClientRecord += Client.PinCode + Seperator;
	strClientRecord += Client.Name + Seperator;
	strClientRecord += Client.Phone + Seperator;
	strClientRecord += to_string(Client.AccountBalance);
	return strClientRecord;
}
string ConvertRecordToLineUser(sUser User, string Seperator) {
	string strUserRecord = "";
	strUserRecord += User.Name + Seperator;
	strUserRecord += User.Password + Seperator;
	strUserRecord += to_string(User.Permissions);
	return strUserRecord;
}
string  ReadClientAccountNumber() {
	string  AccountNumber = "";
	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;
}
sClient ConvertLinetoRecord(string Line, string Seperator) {
	sClient Client;
	vector<string > vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);
	//cast string  to double
	return Client;

}
vector <sClient> LoadCleintsDataFromFile(string FileName) {
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	//read Mode
	if (MyFile.is_open()) {
		string  Line;
		sClient Client;
		while (getline(MyFile, Line)) {
			Client = ConvertLinetoRecord(Line, Seperator);
			vClients.push_back(Client);
		}
		MyFile.close();
	} return vClients;
}

vector <sUser> LoadUsersDataFromFile(string FileName) {
	vector <sUser> vUsers;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	//read Mode
	if (MyFile.is_open()) {
		string  Line;
		sUser User;
		while (getline(MyFile, Line)) {
			User = ConvertLineToUserRecord(Line, Seperator);
			vUsers.push_back(User);
		}
		MyFile.close();
	} return vUsers;
}
void PrintClientCard(sClient Client) {
	cout << "\nThe following are the client details:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code     : " << Client.PinCode;
	cout << "\nName         : " << Client.Name;
	cout << "\nPhone        : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}
void PrintUserCard(sUser User) {
	cout << "\nThe following are the client details:\n";
	cout << "\nName         : " << User.Name;
	cout << "\nPassword     : " << User.Password;
	cout << "\nPermissions     : " << User.Permissions;
}
vector <sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients) {
	fstream MyFile;

	MyFile.open(FileName, ios::out);
	//overwrite
	string  DataLine;
	if (MyFile.is_open()) {
		for (sClient C : vClients) {
			if (C.MarkForDelete == false) {

				DataLine = ConvertRecordToLine(C, Seperator);
				MyFile << DataLine << endl;

			}
		}
		MyFile.close();
	} return vClients;
}
vector <sUser> SaveUsersDataToFile(string FileName, vector<sUser> vUsers) {
	fstream MyFile;

	MyFile.open(FileName, ios::out);
	//overwrite
	string  DataLine;
	if (MyFile.is_open()) {
		for (sUser C : vUsers) {
			if (C.MarkForDelete == false) {

				DataLine = ConvertRecordToLineUser(C, Seperator);
				MyFile << DataLine << endl;

			}
		}
		MyFile.close();
	} return vUsers;
}
void BackToMainMenue() {
	cout << "Press any key to go back to Main Menu...";
	cin.ignore(); // Clear the input buffer
	cin.get();    // Wait for a key press
	system("cls"); // Clear the screen
	//system("pause>0");
	ShowMainMenue();
}

void Exiting() {
	cout << "Exiting the CLI" << endl;
	cout << "====================================================" << endl;
	cout << "\t\tEND PROGRAM:(\n";
	cout << "====================================================" << endl;
	exit(0);
}