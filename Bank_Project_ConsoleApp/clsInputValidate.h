#pragma once

#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate
{
public:
    bool ReadTrueOrFalse(string Message, string ErrorMessage)
    {
        bool TrueOrFalse = 1;
        short Num = ReadShortNumberBetween(0, 1, Message, ErrorMessage);
        switch (Num)
        {
        case 1:
            return 1;
            break;
        default:
            return 0;
            break;
        }
    }

    static bool IsNumberBetween(short Number, short From, short To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    static bool IsNumberBetween(int Number, int From, int To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    static bool IsNumberBetween(float Number, float From, float To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    static bool IsNumberBetween(double Number, double From, double To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        // Date>=From && Date<=To
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
        {
            return true;
        }

        // Date>=To && Date<=From
        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
        {
            return true;
        }

        return false;
    }

    static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        short Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static char ReadChar(string Message = "")
    {
        char Char;
        cout << Message;
        cin >> Char;
        return Char;
    }

    static short ReadShortNumberBetween(short From, short To, string Message = "Enter a number: ", string ErrorMessage = "Number is not within range, Enter again:")
    {
        short Number;
        cout << Message;
        cin >> Number;
        while ((!(Number >= From && Number <= To)) || cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << ErrorMessage;
            cin >> Number;
        }
        return Number;
    }

    static int ReadIntNumber(string Message = "", string ErrorMessage = "Invalid Number, Enter again\n")
    {
        int Number = 0;

        cout << Message;
        cin >> Number;

        while (cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << ErrorMessage;
            cin >> Number;
        }

        return Number;
    }

    static int ReadIntNumberBetween(int From, int To, string Message = "", string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        int Number;
        cout << Message;
        cin >> Number;
        while ((!(Number >= From && Number <= To)) || cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << ErrorMessage;
            cin >> Number;
        }
        return Number;
    }

    static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        double Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        double Number = ReadDblNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadDblNumber();
        }
        return Number;
    }

    static float ReadFloatNumber(string Message = "", string ErrorMessage = "Invalid Number, Enter again\n")
    {
        float Number = 0;

        cout << Message;
        cin >> Number;

        while (cin.fail() || cin.peek() != '\n')
        { // user didn't input a number
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << ErrorMessage;
            cin >> Number;
        }

        return Number;
    }

    static float ReadFloatNumberBetween(float From, float To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        float Number = ReadFloatNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadDblNumber();
        }
        return Number;
    }

    int ReadPositiveInt(string Message = "", string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        int Number;

        cout << Message;
        cin >> Number;

        while (Number <= 0 || cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << ErrorMessage;
            cin >> Number;
        }

        return Number;
    }

    short ReadPositiveShort(string Message = "Please enter positive number\n", string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        short Number;

        cout << ErrorMessage;
        cin >> Number;

        while (Number <= 0 || cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << Message;
            cin >> Number;
        }

        return Number;
    }

    static bool IsValideDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

    static string ReadString(bool IgnoreEnterPress = 1, bool FirstInLoop = 0)
    {
        string St;

        if (FirstInLoop && IgnoreEnterPress)
        {
            cin.ignore(1, '\n');
            getline(cin >> ws, St);
            return St;
        }
        if (FirstInLoop)
        {
            getline(cin >> ws, St);
            return St;
        }
        if (IgnoreEnterPress)
        {
            cin.ignore(1, '\n');
            getline(cin, St);
        }
        else
        {
            getline(cin, St);
        }
        return St;
    }
};