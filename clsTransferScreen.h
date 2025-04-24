#pragma once
#include<iostream>
#include<fstream>

#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsTransferScreen :protected clsScreen

{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}


	static string _ReadAccountNumber(string Text)
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer "<<Text<<" :";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}


	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}


public:


	//clsBankClient åÐÇ Íáí ááÊÍæíá ãä ÍÓÇÈ Çáì ÍÓÇÈ Íá ÇÈæ åÏæÏ ÞÓã ÇáßæÏ Ýí ÇßËÑ ãä ÏÇáÉ æÌÚá ÏÇáÉ ÇáÊÍæíá Ýí 
	
	//static void ShowTransferScreen()
	//{
	//	_DrawScreenHeader("\tTransfer Screen");
	//	string AccountNumber;
	//
	//	cout << "Please Enter Account Number to Transfer From :";
	//	 AccountNumber = clsInputValidate::ReadString();
	//
	//	 while (!clsBankClient::IsClientExist(AccountNumber))
	//	 {
	//		 cout << "\nAccount number is not found, choose another one: ";
	//		 AccountNumber = clsInputValidate::ReadString();
	//	 }
	//	
	//
	//	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	//	_PrintClient(Client1);
	//	
	//	
	//	cout << "\n\nPlease Enter Account Number to Transfer to :";
	//	 AccountNumber = clsInputValidate::ReadString();
	//
	//	while (!clsBankClient::IsClientExist(AccountNumber))
	//	{
	//		cout << "\nAccount Number not found ,plase enter another one :";
	//		AccountNumber = clsInputValidate::ReadString();
	//	}
	//
	//	clsBankClient Client2 = clsBankClient::Find(AccountNumber);
	//	_PrintClient(Client2);
	//
	//	cout << "\n\nEnter Transfer Amount :";
	//	int Amount = clsInputValidate::ReadIntNumber();
	//
	//	while (Amount > Client1.AccountBalance)
	//	{
	//		cout << "\nAnount Exceeds the available Balance ,Enter another Amount ?";
	//		Amount = clsInputValidate::ReadIntNumber();
	//	} 
	//
	//	cout << "\nAre you sure do yo want to perform this operetion ?y/n ?";
	//	string Answer = clsInputValidate::ReadString();
	//	if (Answer == "y" || Answer == "Y")
	//	{
	//		//Client1.AccountBalance -= Amount;
	//		//Client1.Save();
	//		Client1.Withdraw(Amount);
	//
	//		//Client2.AccountBalance += Amount;
	//		//Client2.Save();
	//		Client2.Deposit(Amount);
	//
	//		cout << "\nTransfer done Successfully :-)";
	//
	//		_PrintClient(Client1);
	//		cout << endl;
	//		_PrintClient(Client2);
	//
	//	}
	//
	//
	//
	//}



	// Íá ÇÈæ åÏåæÏ 


	static void ShowTransferScreen()
	{

		_DrawScreenHeader("\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("from"));

		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("to"));

		while (DestinationClient.AccountBalance == SourceClient.AccountBalance)
		{
			cout << "\nYou can not Transfer to the same Acc.\n";
			DestinationClient = clsBankClient::Find(_ReadAccountNumber("to"));

		}

		_PrintClient(DestinationClient);

		float Amount = ReadAmount(SourceClient);


		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
				//SourceClient.TransferLog(Amount, DestinationClient);
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}
		}

		
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);


	}

	

};

