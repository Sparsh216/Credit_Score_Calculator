//Header files
#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include "windows.h"
using namespace std;

//Function to set the cursor position in the console window
void getoxy(int x, int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Class Definition
class applicant
{
	string name;
	int age;
	string address;
	int m_sal;
	int h_loan;
	int p_loan;
	int num_chq_bounce;
	char own_house;
	char spouse_working;
	char dependent_parents;
	int company_tier;
	
//	Class Function Declaration	
	public:
		void get_data();
		int calc_liability();
		void display_score();
};

//Function for storing and receiving loan application's details
void applicant::get_data()
{
	system("cls");
	cout<<"Name of the applicant: ";
	getline(cin,name);
	cout<<"Age: ";
	cin>>age;
	cin.clear();
	cin.ignore(1000, '\n');
	cout<<"Montly Salary: ";
	cin>>m_sal;
	cout<<"Total home loan: ";
	cin>>h_loan;
	cout<<"Total personal loan: ";
	cin>>p_loan;
	cout<<"Number of check bounce in last six months: ";
	cin>>num_chq_bounce;
	cout<<"Own house? (y or n): ";
	cin>>own_house;
	cout<<"Spouse working? (y or n): ";
	cin>>spouse_working;
	cout<<"Dependent parents? (y or n): ";
	cin>>dependent_parents;
	cout<<"Company Tier: ";
	cin>>company_tier;
} //End of Get Data

//Function for calculating credit score
int applicant::calc_liability()
{
	int score=0; //Initializing the score variable for storing credit score
	int liability;
	if(age>26 && age<=30)
	score=score+2;
	else if(age>30 && age<=35)
	score++;
	else
	score--;
	liability=h_loan+p_loan;
	if(liability<=m_sal/4)
	score=score+5;
	if(liability>m_sal/4 && liability<=m_sal/3)
	score=score+3;
	if(liability>m_sal/3 && liability<=m_sal/2)
	score=score+2;
	if(liability>m_sal/2)
	score--;
	if(num_chq_bounce>1)
	score=score-2;
	if(num_chq_bounce==1)
	score=score-1;
	if(num_chq_bounce==0)
	score=score+1;
	if(p_loan>h_loan)
	score--;
	else
	score++;
	if(own_house=='y')
	score++;
	if(spouse_working=='y')
	score++;
	if(dependent_parents=='n')
	score++;
	else
	score--;
	if(company_tier==1)
	score=score+3;
	if(company_tier==2)
	score=score+2;
	else
	score++;
	return score;
}//End of calc_liability

//Function for dispalying credit score and applicant rating
void applicant::display_score()
{
	int sc=calc_liability();//Calling function to get the score 
//	Displaying the result
	system("cls")
	if(sc>9)
	cout<<"The applicant "<<name<<" is at low risk.\nCredit score ="<<sc<<"\nCredit can be given.";
	else
	{
		if(sc>5 && sc<=9)
		cout<<"The applicant "<<name<<" is at average risk.\nCredit score ="<<sc<<"\nCredit can be given with due precaution.";
		else
		cout<<"The applicant "<<name<<" is at high risk.\nCredit score ="<<sc<<"\nCredit cannot be given.";
	}
	getch();
}//End of Display function

//Main Function
int main()
{
	char flag='f';
	applicant a;
	char ch;
	while(1)
	{
		system("cls");
		getoxy(31,8);
		cout<<"Credit Calculation";
		getoxy(31,9);
		cout<<"__________________";
		getoxy(22,12);
		cout<<"1 - Enter Loan Applicant's Details";
		getoxy(22,13);
		cout<<"2 - Display Credit Score";
		getoxy(22,14);
		cout<<"3 - Exit";
		getoxy(22,16);
		cout<<"Select an option by typing the number code: ";
		ch=getch();
		switch(ch)
		{
			case('1'):
			{
				a.get_data();
				flag='t';
				break;	
			}
			case('2'):
			{
				if(flag=='f')
				{
					getoxy(22,18);
					cout<<"Loan applicant's details not yet entered! Press any key to continue...";
					getch();
				}
				else
				a.display_score();
				break;
			}
			case('3'):
			{
				exit(1);
				break;
			}
			default:
			{
				getoxy(22,18);
				cout<<"Invalid Choice! Press any key to continue...";
				getch();	
			}
		}//End of switch
	}//End of while block
}//End of main
			
		
