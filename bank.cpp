//bank system console application

#include <iostream>
#include <string>
#include<process.h>

using namespace std;

class depo{
	public:
			virtual void deposit()=0;
};

class Account
{
	public:
		int acc;
		int acc_type;
		string name;
		int bankSave;
		int bankBalance;
		int option;
		int bankCurrent;
		
	void customerInfo()
	{
		cout << "ENTER THE CUSTOMER INFORMATION \n";
		cout << "Customer Name: \n";
		cin >> name;
		cout << "Account Number:";
		cin >> acc;
		cout << "\n Account Type: (enter 1 for SavingsAcc, 2 for CurrentAcc) ";
		cin >> acc_type;
	}
	//queries for service.
	void serviceEnquire()
	{		
		cout << "Choose the service you want below: \n";
		cout << "1. Deposit \n";
		cout << "2. Withdrawal \n";
		cout << "3. Check Balance \n";
		cin >> option;
	}

	
	void checkBalance()
	{
		cout << bankBalance;
	}
	
};

class sav_act : Account,depo
{
	public:
	int depositAmt;
	
	void deposit()
	{
		cout << "enter the amount you want to deposit : \n";
		cin >> depositAmt;
		cout << "\n Account Type to transact: (enter 1 for SavingsAcc, 2 for CurrentAcc) ";
		cin >> acc_type;
		if (acc_type == 1)
		{
			if (depositAmt != 0){
			bankSave += depositAmt;
		} else {
			cout << "enter a valid amount!";
		}	
		} else if (acc_type == 2) {
			if (depositAmt != 0){
			bankCurrent += depositAmt;
		} else {
			cout << "enter a valid amount!";
		}	
		} else {
			cout << "choose a valid option";
		}
	}
	
	void withdraw()
	{
		int withdrawal;
		
		cout << "Enter the amount you wish to withdraw : \n";
		cin >> withdrawal;
		cout << "\n Account Type to transact: (enter 1 for SavingsAcc, 2 for CurrentAcc) ";
		cin >> acc_type;
		if (acc_type == 1)
		{
			if (withdrawal != 0){
			bankSave += withdrawal;
		} else {
			cout << "enter a valid amount!";
		}	
		} else if (acc_type == 2) {
			if (depositAmt != 0){
			bankCurrent += withdrawal;
		} else {
			cout << "enter a valid amount!";
		}	
		} else {
			cout << "choose a valid option";
		}
	
	}
};

class cur_act : public Account
{
	public:
		int penalty;
		int balance;
		int CI;
		int P;
		int R;
		int T;
		void computeIntrest();
	void calcInterest()
	{
		CI = (P * R * T);	
	}
	
	void calcPenalty ()
	{
		if (balance <= 1000 )
		penalty += bankBalance;
}
};

int main()
{
	Account a;
	sav_act s;
	a.customerInfo();
	a.serviceEnquire();	
	{
	if (a.option == 1 ){
			s.deposit();
			
		} else if (a.option == 2){
			s.withdraw();
			
		} else if (a.option == 3){
			a.checkBalance();
		}
	
	}	
		return 0;
}

