#pragma once
//#pragma warning (disable:4996) 

#include<iostream>
#include"clsUser.h"
#include"Global.h"
#include"clsDate.h"
using namespace std;
class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\n\t\t\t\t\t\tUser :" << CurrentUser.UserName;
      
        //1 åÐå ØÑíÞå áØÈÇÚå ÇáÊÇÑíÎ 
        //clsDate Date = clsDate::GetSystemDate();
        //cout << "\n\t\t\t\t\t\tDate :" << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

        //2
        cout << "\n\t\t\t\t\t\tDate :" << clsDate::DateToString(clsDate()) << "\n\n";



    }


    static bool CheckAccessRights(clsUser::enPermissions Permissions)
    {
        if (!CurrentUser.CheckAccessPermission(Permissions))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }


    //ÈåÐå ÇáØÑíÞå íÌÈ ÚáíäÇ Çä äÓÊÏÚí åÐå ÇáÏÇáÉ Ýí ßá ÔÇÔÇå áÐÇáß äÖíÝå Ýí ÇáåÏÑ ÇÝÖá 
   // static void ShowDateAndUserName()
   // {
   //     cout << "\n\t\t\t\t\t\tUser :"<<CurrentUser.UserName;
   //
   //     //time_t now = time(0);
   //     //tm* time = localtime(& now);
   //
   //     //cout << "\n\t\t\t\t\t\tDate:" << time->tm_mday << "/" << time->tm_mon +1 << "/" << time->tm_year + 1900 << endl;
   //     clsDate Date = clsDate::GetSystemDate();
   //
   //     cout << "\n\t\t\t\t\t\tDate :" << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
   //
   // }
};

