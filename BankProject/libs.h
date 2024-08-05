#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "model.h"

using namespace std;
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void StartApp(); // Declare StartApp here
int ReadNumberInRange(int From, int To, string Message);
void Routing(short Num);
void pop();
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
void PrintClientCard(sClient Client) {
	cout << "\nThe following are the client details:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code     : " << Client.PinCode;
	cout << "\nName         : " << Client.Name;
	cout << "\nPhone        : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
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

void pop() {
	cout << "Press any key to go back to Main Menu...";
	cin.ignore(); // Clear the input buffer
	cin.get();    // Wait for a key press
	system("cls"); // Clear the screen
	StartApp();
}