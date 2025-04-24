#include<iostream>
using namespace std;

#include"clsBankClient.h"
#include"clsMainScreen.h"
#include"clsLoginScreen.h"

// locked the system after 3 trial (My Answer)
//#include"Global.h"

int main()
{
	//clsMainScreen::ShowMainMenue();

    // locked the system after 3 trial (My Answer)
	//while (!LoginFaild)
	//{
	//	clsLoginScreen::ShowLoginScreen();
	//}


	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}

	//cout<<clsUtil::EncryptPassword("1234",2);

}