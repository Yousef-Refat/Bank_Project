#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{

private:
    enum enTransactionsMenueOptions
    {
        eDeposit = 1,
        eWithdraw = 2,
        eShowTotalBalance = 3,
        eTransfer = 4,
        eTransferLog = 5,
        eShowMainMenue = 6

    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("clear");
            _ShowDepositScreen();

            cout << "\n\nPress Enter key to go back to Transactions Menue...";
            cin.get();
            ShowTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eWithdraw:
        {
            system("clear");
            _ShowWithdrawScreen();

            cout << "\n\nPress Enter key to go back to Transactions Menue...";
            cin.get();
            ShowTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("clear");
            _ShowTotalBalancesScreen();

            cout << "\n\nPress Enter key to go back to Transactions Menue...";
            cin.get();
            ShowTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTransfer:
        {
            system("clear");
            _ShowTransferScreen();

            cout << "\n\nPress Enter key to go back to Transactions Menue...";
            cin.get();
            ShowTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTransferLog:
        {
            system("clear");
            _ShowTransferLogScreen();

            cout << "\n\nPress Enter key to go back to Transactions Menue...";
            cin.get();
            ShowTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eShowMainMenue:
        {

        }
        }
    }

public:
    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return; 
        }

        system("clear");
        _DrawScreenHeader("\tTransactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }
};
