#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
class casino
{
	public:
		string players_name,choice;
		int total_amount,bet_amount,bet_number,dice;
		int details();
		int rules();
		int betting();
};
casino::details()
{
	cout<<"\t\t\t=========WELCOME TO CASINO WORLD========";
	cout<<"\nWhat's Your Name : "	;
	cin>>players_name;
	cout<<"\nEnter the starting balance to play game : $";
	cin>>total_amount;
}
casino::rules()
{
	system("cls");
	cout<<"\t\t\t========CASINO NUMBER GUESSING RULES!========";
	cout<<"\n\n\t\t\t1. Choose a number between 1 to 10";
	cout<<"\n\t\t\t2. Winner gets 10 times of the money bet";
	cout<<"\n\t\t\t3. Wrong bet, and you lose the amount you bet";
}
casino::betting()
{
	char choic;
	cout<<"\nYour current balance is $ "<<total_amount;
	x:
	cout<<"\nHey "<<players_name<<" enter amount to bet: $";
	cin>>bet_amount;
	if(bet_amount>total_amount)
	{
		if(total_amount==0)
		{
			cout<<"you have zero balance\n";
			cout<<"Want to add money in your playing account(y,n): ";
			cin>>choic;
			if(choic=='y' || choic=='Y')
			{
				cout<<"\nEnter the amount: $";
				cin>>total_amount;
				cout<<"Amount added succesfully";
				cout<<"\nyour current balance is: $"<<total_amount;
				goto x;
			}
			else
			{
				cout<<"\nOops zero balance you can't play now";
				exit(0);
			}
		}
		cout<<"Betting amount exceeding total amount\nplease renter proper amount";
		cin>>bet_amount;
	}
	total_amount-=bet_amount;
	cout<<"\nGuess any betting number between 1 & 10 :";
	cin>>bet_number;
	if(bet_number>10 || bet_number<1)
	{
		cout<<"\nThe number should be between 1 & 10\nRenter the number: ";
		cin>>bet_number;
	}
	srand(time(0));
	dice = rand()%10 + 1;
	if(dice==bet_number)
	{
		cout<<"Congratulations you win the bet \n";
		cout<<"your current balance is: $"<<total_amount+(bet_amount*10);
	}
	else
	{
		cout<<"Oops you lose the bet.... \n";
		cout<<"The betting number was "<<dice;
		cout<<"\nYour current balance is: $"<<total_amount;
	}
	
}
int main()
{
	char choice;
	casino c;
	c.details();
	m:
	c.rules();
	c.betting();
	cout<<"\nDo you want to play again(y/n)";
	cin>>choice;
	if(choice=='y'||choice=='Y')
	{
		goto m;
	}
	else
	{
		cout<<"Thanks for playing. Your balance is : $"<<c.total_amount;
		exit(0);
	}
}