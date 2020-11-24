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
		const string fill = "0123456789";
		srand(time(0));
		for (int i = 0; i < 8; i++)
		{
			number += fill[rand() % 10];
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

	void SetBalance(string number)
	{
		if (number == this->number)
		{			
			bool flag = false;
			do 
			{				
				cout << "1.Add cash" << endl;
				cout << "2.Withdraw cash" << endl;
				cout << "3.Show balance" << endl;
				cout << "4.Exit" << endl;
				int switch_on{}, cash;
				cin >> switch_on;
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
					} while (cash > balance);
					break;
				case 3:
					cout << "Your balance is: " << balance << " " << currency << endl;
					break;
				case 4:
					cout << "Goodbye!" << endl;
					flag = true;
				default:
					cout << "Error choise. Try again." << endl;
					break;
				}
			} while (flag == false);
			
		}
		else
		{
			cout << "Your data is incorrect. Try again." << endl;
		}
	}
	string EnterPIN()
	{
		
		unsigned short pincode, untrue = 0;		
		do
		{ 
			cout << "Enter PIN code: ";
			cin >> pincode;
			if (pincode == this->pincode)
			{
				return(number);
			}
			else
			{
				cout << "PIN code is untrue. Try again." << endl;
				untrue++;
			}
		} while (untrue < 3);
		if (untrue >= 3)
		{
			cout << "Your account is blocked." << endl;
			return string();
		}
	}
	
};

int main() 
{
	Account firstAccount;
	firstAccount.CreateAccount();
	string account_number = firstAccount.EnterPIN();	
	firstAccount.SetBalance(account_number);
	
	system("pause");
	return 0;
}