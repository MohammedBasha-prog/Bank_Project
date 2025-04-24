#pragma once
#pragma warning(disable:4669)

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include <fstream>
#include "clsString.h"
class clsLoginScreen :protected clsScreen
{

private:


	//static void _Login()
	//{
	//
	//	bool LoginFild = false;
	//	do
	//	{
	//
	//		
	//		cout << "\nEnter User name :";
	//		string UserName = clsInputValidate::ReadString();
	//
	//		cout << "\nEnter password :";
	//		string Password = clsInputValidate::ReadString();
	//
	//
	//		CurrentUser = clsUser::Find(UserName, Password);
	//		if (CurrentUser.IsEmpty())
	//		{
	//			LoginFild = true;
	//			
	//			cout << "\nEmpty user ther is no user ,enter agin :";
	//		}
	//		else
	//		{
	//			LoginFild = false;
	//		}
	//
	//	} while (LoginFild);
	//
	//	clsMainScreen::ShowMainMenue();
	//}

	// locked the system after 3 trial (My Answer)
	//static  void _Login()
	//{
	//	
	//
	//
	//	string Username, Password;
	//	int countMistak = 1;
	//	do
	//	{
	//
	//		if (LoginFaild)
	//		{
	//			system("cls");
	//			_DrawScreenHeader("\t  Login Screen");
	//			cout << "\nInvlaid Username/Password!\n\n";
	//			cout << "You have " << 3 - countMistak << " Trials to login :" << endl;
	//			countMistak++;
	//			
	//		}
	//
	//		cout << "Enter Username? ";
	//		cin >> Username;
	//
	//		cout << "Enter Password? ";
	//		cin >> Password;
	//
	//		CurrentUser = clsUser::Find(Username, Password);
	//
	//		LoginFaild = CurrentUser.IsEmpty();
	//		
	//		if (LoginFaild == false)
	//		{
	//			break;
	//		}
	//
	//	} while (countMistak!=3 );
	//
	//	if (!LoginFaild)
	//	{
	//		clsMainScreen::ShowMainMenue();
	//	}
	//	else
	//	{
	//		cout << "\nyour locked after 3 trials";
	//	}
	//	
	//
	//}

	

	static bool _Login()
	{
		string UserName, Password;
		bool LoginFild = false;
		
		short FaildLoginCount = 0;

		do
		{
			if (LoginFild)
			{
				FaildLoginCount++;
				system("cls");
				_DrawScreenHeader("\t Login Screen");
				cout << "Invlaid Username/Password!";
				cout << "\nYou have " << (3 - FaildLoginCount)
					<< " Trial(s) to login.\n\n";
			}

			if (FaildLoginCount == 3) // ßÊÈäÇå åÐÇ åäÇ ÚáÇ ÔÇä ÇÐÇ ÇÕÈÍÊ ËáÇË ãÍÇæáÇÊ áÇíÞÑÇ ÇáíæÒÑ äíã íØÈÚ áå ØæÇáí áÏíß 0 ãÍÇæáÇÊ æíÎÑÌå
			{
				cout << "\nYour are Locked after 3 faild trails \n\n";
				return false;
			}

			cout << "Enter UserName: ";
			cin >> UserName;

			cout << "Enter Password :";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFild = CurrentUser.IsEmpty();

			


		} while (LoginFild);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}

	

public:


	//1
	//static void ShowLoginScreen()
	//{
	//	system("cls");
	//	_DrawScreenHeader("\t  Login Screen");
	//	_Login();
	//
	//}


	//2
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	
	}


};


