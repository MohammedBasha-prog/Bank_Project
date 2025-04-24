/*
* 
*   my enswer
#pragma once
#include<string>
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"

class clsCurrencyCalculatorScreen :protected clsScreen
{
private:
	static string  _ReadCurrencyCode()
	{
		string CurrencyCode = "";
		cout << "\nPlease Enter Currency Code :";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency code not found ,please enter another one :";
			CurrencyCode = clsInputValidate::ReadString();
		}

		
		return CurrencyCode;
	}



	static void _PrintCurrency(clsCurrency Currency)
	{
		
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		_DrawScreenHeader("\t Currency Calculato Screen");

		string  CurrencCode = _ReadCurrencyCode();
	
		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencCode);

		CurrencCode = _ReadCurrencyCode();

		clsCurrency Currency2= clsCurrency::FindByCode(CurrencCode);

		cout << "\nPlease Enter Amount to Exchange :";
		float Amount = clsInputValidate::ReadFloatNumber();

		if ( clsString::UpperAllString(Currency2.CurrencyCode()) == "USD")

		{

			float Exchange = clsCurrency::CurrencyCalculatorToUSD(Currency1, Amount);

			cout << "Convert From :";
			cout << "\n________________________\n";
			_PrintCurrency(Currency1);

			cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " =" << Exchange << " USD";
		}
		else
		{

			float Exchange = clsCurrency::CurrencyCalculatorToUSD(Currency1, Amount);

			cout << "Convert From :";
			cout << "\n________________________\n";
			_PrintCurrency(Currency1);

			cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " << Exchange << " USD";

			cout << "\n\nConverting from USD to:";
			cout << "\n\nTo :";
			cout << "\n________________________\n";
			_PrintCurrency(Currency2);
			Exchange = clsCurrency::CurrencyCalcualatorFromUSD(Currency2, Exchange);
			cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " << Exchange <<" " << Currency2.CurrencyCode();

		}


	}

};


*/

#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen :protected clsScreen

{
private:

    static float _ReadAmount()
    {
        cout << "\nEnter Amount to Exchange: ";
        float Amount = 0;

        Amount = clsInputValidate::ReadFloatNumber();
        return Amount;
    }

    static clsCurrency _GetCurrency(string Message)
    {

        string CurrencyCode;
        cout << Message << endl;

        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;

    }


    static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
    {

        cout << "\n" << Title << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry       : " << Currency.Country();
        cout << "\nCode          : " << Currency.CurrencyCode();
        cout << "\nName          : " << Currency.CurrencyName();
        cout << "\nRate(1$) =    : " << Currency.Rate();
        cout << "\n_____________________________\n\n";

    }

    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {

        _PrintCurrencyCard(Currency1, "Convert From:");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInUSD << " USD\n";

        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";

        _PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

    }


public:

    static void ShowCurrencyCalculatorScreen()
    {
        char Continue = 'y';

        while (Continue == 'y' || Continue == 'Y')
        {
            system("cls");

            _DrawScreenHeader("\tUpdate Currency Screen");

            clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
            clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
            float Amount = _ReadAmount();

            _PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

            cout << "\n\nDo you want to perform another calculation? y/n ? ";
            cin >> Continue;

        }


    }
};

