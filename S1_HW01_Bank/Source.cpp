#include<iostream>
#include<string>
#include<time.h>

using namespace std;

class Account
{
private:
	unsigned short pincode;
	string number;
	float balance;
	string currency;

public:
	void CreateAccount()
	{
		int pin1, pin2, switch_on;
		srand(time(0));
		for (int i = 0; i < 8; i++)
		{
			number[i]= rand() % 10;
		}
		cout << "Number of your account is: " << number << endl;
		do 
		{
			cout << "Enter PIN code: ";
			cin >> pin1;
			cout << "Confirm PIN code: ";
			cin >> pin2;
			if (pin1 == pin2)
			{
				pincode = pin1;
			}
			else
			{
				cout << "Different code. Try again." << endl;
			}
		} while (pin1 != pin2);
		cout 
			<< "Choise your currency:\n1.UAN\n2.USD\n3.EUR\n->";
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			currency = "UAN";
			break;
		case 2:
			currency = "USD";
			break;
		case 3:
			currency = "EUR";
			break;
		default:
			break;
		}
		balance = 0;

	}
	void GetBalance(string number)
	{
		if (number == this->number)
		{
			cout << "Your balance is: " << balance << " " << currency << endl;
		}
		else
		{
			cout << "Your data is incorrect. Try again." << endl;
		}
	}
	void SetBalance(string number)
	{
		if (number == this->number)
		{
			cout << "Your balance is: " << balance << " " << currency << endl;
			cout << "1.Add cash" << endl;
			cout << "2.Withdraw cash" << endl;
			int switch_on{}, cash;
			switch (switch_on)
			{
			case 1:
				cout << "Enter the amount of cash to add: ";
				cin >> cash;
				balance += cash;
				cout << "Now your balance is: " << balance << " " << currency << endl;
				break;
			case 2:
				do 
				{
					cout << "Enter the amount of cash to withdraw: ";
					cin >> cash;
					if (cash <= balance)
					{
						balance -= cash;
						cout << "Now your balance is: " << balance << " " << currency << endl;
					}
					else
					{
						cout << "Your balance is less than your want to withdraw.\nTry again." << endl;
					}
					cout << "Now your balance is: " << balance << " " << currency << endl;
				} while (cash > balance);
				break;
			default:
				break;
			}
		}
		else
		{
			cout << "Your data is incorrect. Try again." << endl;
		}
	}
	string EnterPIN()
	{
		
		unsigned short pincode, untrue = 0;		
		cout << "Enter PIN code: ";
		cin >> pincode;
		do
		{ 
			if (pincode == this->pincode)
			{
				return(number);
			}
			else
			{
				cout << "PIN code is untrue. Try again." << endl;
				untrue++;
			}
		} while (untrue < 4);
		if (untrue >= 4)
		{
			cout << "Your account is blocked." << endl;
		}
	}
	
};

int main() 
{
	Account firstAccount;
	firstAccount.CreateAccount();
	string account_number = firstAccount.EnterPIN();	
	firstAccount.SetBalance(account_number);
	firstAccount.GetBalance(account_number);
	system("pause");
	return 0;
}