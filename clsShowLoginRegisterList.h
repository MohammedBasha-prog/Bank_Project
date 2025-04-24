
// clsLoginRegisterScreen.h ·ﬁœ ﬁ„‰« »Õ–› Â–« «·ﬂ·«” Ê«”»œ·‰«Â  
// ·«‰ ÿ—ÌﬁÕ Õ· «·œﬂ Ê— «Œ—Ï
#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"clsScreen.h"
#include"clsUser.h"
#include<string>
#include<iomanip>
class clsShowLoginRegisterList :protected clsScreen
{
private:


	string _UserName;
	string _Password;
	int _Permission;
	string _Date;


	static clsShowLoginRegisterList _ConverDateLineToLoginRegister(string line)
	{
		vector<string>vString = clsString::Split(line, "#//#");
		return clsShowLoginRegisterList(vString[0], vString[1], vString[2], stoi(vString[3]));
	}

	static vector<clsShowLoginRegisterList> _LoudLoginRegisterDateFromFile()
	{
		vector<clsShowLoginRegisterList> vLoginReigster;

		fstream Myfile;
		Myfile.open("LoginRegister.txt", ios::in);
		if (Myfile.is_open())
		{
			string line;
			while (getline(Myfile, line))
			{
				clsShowLoginRegisterList Register = _ConverDateLineToLoginRegister(line);

				vLoginReigster.push_back(Register);
			}
			Myfile.close();
		}
		return vLoginReigster;
	}


	static void _PrintLoginRegisterRecord(clsShowLoginRegisterList Record)
	{
		cout << "\n\t\t| "<< setw(29) << left << Record.GetDate();
		cout << "| " << setw(20) << left << Record.GetUserName();
		cout << "| " << setw(20) << left << Record.GetPassword();
		cout << "| " << setw(20) << left << Record.GetPermission();


	}

public:


	clsShowLoginRegisterList(string Date, string UserName, string Password, int Permission)
	{
		_UserName = UserName;
		_Password = Password;
		_Permission = Permission;

		_Date = Date;
	}

	string GetUserName()
	{
		return _UserName;
	}

	string GetPassword()
	{
		return _Password;

	}

	string GetDate()
	{
		return _Date;
	}

	int GetPermission()
	{
		return _Permission;
	}


	static void ShowLoginRegisterScreen()
	{
		vector<clsShowLoginRegisterList>vLoginRegister = _LoudLoginRegisterDateFromFile();
		_DrawScreenHeader("  LoginRegiter List Screen", "(" + to_string(vLoginRegister.size()) + ") Record(s)");

		cout << "\n\t\t__________________________________________________________________________________________\n";
		cout << "\n\t\t| "<< setw(29) <<left<< "Date/Time";
		cout << "| " <<  setw(20) <<left<< "UserName";
		cout << "| " <<  setw(20) << left << "Password";
		cout << "| " <<  setw(20) << left << "Permission";
		cout << "\n\t\t__________________________________________________________________________________________\n";

	
		for (clsShowLoginRegisterList r : vLoginRegister)
		{
			_PrintLoginRegisterRecord(r);
			cout << endl;
		}
		cout << "\n\t\t__________________________________________________________________________________________\n";


	}


	static vector<clsShowLoginRegisterList> GetLoginRegisterList()
	{

	}

};

