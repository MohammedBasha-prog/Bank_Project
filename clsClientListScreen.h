#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsClientListScreen :protected clsScreen
{

private:
	static void _PrintClientRecordLine(clsBankClient Client)
	{

		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}

public:


	//static void ShowClientsList()
	//{
	//	vector<clsBankClient>vClients = clsBankClient::GetClientList();
	//
	//
	//	clsScreen::_DrawScreenHeader("Client List Screen", "(" + to_string(vClients.size()) + ") Client(s)");
	//	cout << "\n\n\t\t_______________________________________________________________________________________________________\n\n";
	//	cout << "\t\t| " << setw(15) << left << "Account Number";
	//	cout << "| " << setw(20) << left << "Client Name";
	//	cout << "| " << setw(12) << left << "Phone";
	//	cout << "| " << setw(20) << left << "Email";
	//	cout << "| " << setw(10) << left << "Pin Code";
	//	cout << "| " << setw(12) << left << "Balance";
	//	cout << "\n\t\t_______________________________________________________________________________________________________\n";
	//
	//	if (vClients.size() == 0)
	//	{
	//		cout << "\n\t\t\tTher is no client ";
	//	}
	//	else
	//	{
	//		for (clsBankClient c : vClients)
	//		{
	//			_PrintClientRecordLine(c);
	//			cout << endl;
	//		}
	//
	//	}
	//
	//	cout << "\n\t\t_______________________________________________________________________________________________________\n";
	//
	//}



	static void ShowClientsList()
	{


		if (!CheckAccessRights(clsUser::pListClients))
		{
			return;
		}

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\t  Client List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{

				_PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

};



