#include <string>
#include <iostream>
#include <vector>
#include "model.h"
#include "1.h"
using namespace std;
double ReadDoubleNumber(string Message) {
	double Num;
	cout << Message;
	cin >> Num;
	return Num;
}
string ReadString(string Message) {
	string Text;
	cout << Message;
	getline(cin, Text);
	return Text;
}
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
sClient ConvertLineToRecord(string strClientRecord, string Seperator = "#%&#") {
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
void ReadFileByVector(vector<string>& vFile) {
	for (string& Line : vFile) {
		if (!Line.empty())
		{
			sClient Client = ConvertLineToRecord(Line);
			PrintClient(Client);
			cout << endl;
		}
	}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}
void pop() {
	string str = "";
	cout << "Press any key to go back to Main Menue...";
	cin >> str;
	if (str != "") {
		system("pos");
	}
}