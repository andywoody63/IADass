// Program Name: Farnborough Airport Temperature System
// Author: Andrew Woodruff 
// Date: 12/03/2012
// Version: 1.0 
// Description: IAD Assignment. A Program which allows you to input and display temperature information for 5 diffrent 
// locations within Farnborough Airport. 

#include <iostream> 
#include <fstream>   
#include <iomanip> 
#include <string> 
using namespace std;

char areas[5][20] = { "terminal.txt","pass.txt","crew.txt","service.txt","private.txt"};//Store 5 Text File Name's 
char subnames[5][20] = { "Terminal","Passenger Lounge","Crew Lounge","Service Area","Private Lounge"};//Store 5 Area Name's 
char month[12][20] = {"  Jan", "  Feb", "  Mar", "  Apr", "  May",  "  Jun", "  Jul", "  Aug", "  Sep", "  Oct", "  Nov","  Dec"};//Store 12 Month Names  
int whole[5][12];//Whole Airport 2D Array 

void wholeAirportArray()//Read all 5 text files into my main 2D Array
{ 
    for( int i=0; i<=4; i++) 
	{
		ifstream in_file(areas[i]);
		if(!in_file.is_open())
		{
			cout << "  File Could not be Opened or Does not Exist." << endl;
			system("pause");
		}

		for( int j=0; !in_file.eof(); j++)
		{
			in_file >> whole[i][j];
		}
	}
}

void wholeLowest()//Whole Airport Lowest Value Function 
{
	int lowestrow = 0;
	int lowestcol = 0;

	for( int i=0; i<=4; i++)
	{
		for( int j=0; j<=11; j++)
		{
			if(whole[lowestrow][lowestcol] > whole[i][j])
			{
				lowestrow = i;
				lowestcol = j;
			}
		}
	}
	cout << "  Lowest Value is:  " << whole[lowestrow][lowestcol] << ", Area:  " << subnames[lowestrow] << ", Month:" << month[lowestcol] << "\n\n\n"; system("pause");
}

void wholeHighest()//Whole Airport Highest Value Function 
{
	int highestrow = 0;
	int highestcol = 0;

	for( int i=0; i<=4; i++)
	{
		for( int j=0; j<=11; j++)
		{
			if(whole[highestrow][highestcol] < whole[i][j])
			{
				highestrow=i;
				highestcol=j;
			}
		}
	}
	cout << "  Highest Value is:  " << whole[highestrow][highestcol] << ", Area:  "<< subnames[highestrow] <<  ", Month:" << month[highestcol] << "\n\n\n"; system("pause");
}

void wholeAverage()//Whole Airport Average Value Function 
{
	int sum = 0;
	int result = 0;

    for( int j=0; j<=4; j++)
	{
		for( int i=0; i<=11; i++)
		{
			sum = sum + whole[j][i];
		}
	}
    result = sum/60; 
	cout << "  Average Temperature for The Whole Airport for The Year is: " << result << " Degree's" << "\n\n"; system("pause");
}

void wholeTable()//Whole Airport Table Function
{ 
	string row1[12] = {"               Jan ", " Feb ", " Mar ", " Apr ", " May ",  " Jun ", " Jul ", " Aug ", " Sep ", " Oct ", " Nov "," Dec "};
	string row2[1] = {"             -------------------------------------------------------------"};
	string leftcollum[5] = { "  Terminal   | ","  Passenger  | ","  Crew       | ","  Service    | ","  Private    | "};

	cout << "  The Whole Airport Monthly Figures Table" << "\n\n";

	for ( int i=0; i<=11; i++)
    {
       cout << row1[i] << setw(4);
	}
	cout << endl;
	
	for ( int j=0; j<1; j++)
	{
    cout << row2[j];
	}

	cout << setw(3);

	for ( int k=0; k<=4; k++) 
	{
		cout << endl;
		cout << leftcollum[k];

		for( int l=0; l<=11; l++)
		{
			cout << whole[k][l] << " |" << setw(3);
		}
	}	
	cout << "\n\n"; system("pause");
}

void histogram(int choice)//Histogram Function
{  
	cout << "  The " << subnames[choice] << " Monthly Figures Histogram" << "\n\n";

	for ( int i=0; i<=11; i++) 
	{
		cout << month[i] << "  :  ";

        for ( int j=0; j < whole[choice][i]; j++)
		{ 
		        cout << "*"; 
		}
		cout << " " << whole[choice][i] << endl;
	}
	cout << "\n\n"; system("pause");
}

void table(int choice)//Table Function 
{
	string row1[12]={"  Jan |", "Feb |", "Mar |", "Apr |", "May |",  "Jun |", "Jul |", "Aug |", "Sep |", "Oct |", "Nov |","Dec |"};
	string row2[1] = {"  -----------------------------------------------------------------------"};

	cout << "  The " << subnames[choice] << " Monthly Figures Table" << "\n\n";

	for ( int i=0; i<=11; i++)
    {
       cout << row1[i] << setw(6);
	}
	cout << endl;

	for ( int j=0; j<1; j++)
    {
		cout << row2[j];
	}
	cout << endl; 
	cout << "  ";
	setw(2);

	for ( int k=0; k<=11; k++)
    {
       cout << whole[choice][k] << "  |" << setw(3);
	}
	cout << "\n\n\n\n"; system("pause");
}

void average(int choice)//Average Value Function
{
	int sum = 0;
	int result = 0;

	for( int i=0; i<=11; i++)
	{
        sum = sum + whole[choice][i];
	}
	result = sum/12;
	cout << "  The Average Temperature for The " << subnames[choice] << " for the Year: " << result << " Degree's" << "\n\n"; system("pause");
}

void lowest(int choice)//Lowest Value Function
{
	int index = 0; 
	int min = whole[choice][0];

	for( int i=0; i<=11; i++)
	{
		if(min >= whole[choice][i])
		{
			min = whole[choice][i];
		    index = i; 	
		}
	}
	cout << "  Lowest Temperature Month for The " << subnames[choice] << ":"  << month[index] << " with " << min << " Degree's" << "\n\n"; system("pause");
}

void highest(int choice)//Highest Value Function 
{
	int current = 0;
	int max = 0;
	int index = 0; 

	for( int i=0; i<=11; i++)
	{
		current = whole[choice][i];

		if(current > max)
		{
	    max = current;
		index = i; 
		}
	}
	cout << "  Highest Temperature Month for The " << subnames[choice] << ":" << month[index] <<  " with " << max << " Degree's" << "\n\n"; system("pause");
}

void writeToFile(int choice)// Write to File(txt) Function  
{ 
	int temperature[12];

	cout << "  Please Enter the Temperature for Each Month and then Press Enter" << "\n\n";
	ofstream myfile;
	myfile.open (areas[choice]);

	for (int i=0; i<=11; ++i)
	{
		cout << "  Enter " << month[i] <<" Temperature: ";
		cin >> temperature[i];
		cout << endl;
		myfile << temperature[i] << endl;
	}
	myfile.close();

	cout << "  Writen to The " << subnames[choice] << " txt file." << "\n\n"; system("pause"); 
}

void wholeAirport()//Whole Airport Menu 
{
	char choice3;

		cout << "                  WHOLE AIRPORT MENU" << "\n";
		cout << "  ---------------------------------------------------" << "\n";
        cout << "  Select one of the Following options by Entering" << "\n";
        cout << "  it's Number in the Prompt Below and Pressing Enter." << "\n";
		cout << "  ---------------------------------------------------" << "\n\n";
		cout << "  1. Highest Temperature Month and Figure" << "\n";  
        cout << "  2. Lowest Temperature Month and Figure" << "\n";
        cout << "  3. Average Temperature for the Year" << "\n";
        cout << "  4. A Table Showing the Years Temperatures Month by Month" << "\n\n\n";
                
		cin.clear();
		cout << "  Choice... "; 
        cin >> choice3; 
		cout << "\n\n\n";
     
		switch (choice3)
		{
			case '1':
				wholeHighest(); break;			
			case '2':
				wholeLowest(); break;
			case '3':
				wholeAverage(); break;
			case '4':
				wholeTable(); break;
			default: 	
				cout << "  Invalid Choice, Please Enter a Number Between 1 and 4" << "\n\n\n\n\n"; system("pause");
		}
}

void subMenu(int choice) //Sub Menu 
{
	char choice2;

		cout << "                    " << subnames[choice] << " Menu" << "\n";
		cout << "  ---------------------------------------------------" << "\n";
		cout << "  Select one of the Following options by Entering" << "\n";
		cout << "  it's Number in the Prompt Below and Pressing Enter." << "\n";
		cout << "  ---------------------------------------------------" << "\n\n";
		cout << "  1. Enter Monthly Figures and Save Them to File" << "\n";  
		cout << "  2. Highest Temperature Month and Figure" << "\n";
		cout << "  3. Lowest Temperature Month and Figure" << "\n";
		cout << "  4. Average Temperature for the Year" << "\n";
		cout << "  5. A Table Showing the Years Temperatures Month by Month" << "\n";
		cout << "  6. A Histogram of the Monthly Figures(Graphical Representation)" << "\n\n\n";
    
		cin.clear();
		cout << "  Choice.. "; 
		cin >> choice2; 
		cout << "\n\n\n";
     
		switch (choice2)
		{
			case '1':
				writeToFile(choice); break;			
			case '2':
				highest(choice); break;
		    case '3':
				lowest(choice); break;
			case '4':
				average(choice); break;
			case '5':
				table(choice); break;
			case '6':
				histogram(choice); break;
			default: 	
				cout << "  Invalid Choice, Please Enter a Number Between 1 and 6" << "\n\n\n\n\n"; system("pause"); 
		}
}

void main() //Main Menu 
{
	int choice;
    wholeAirportArray(); //Read All Data from 5 txt files into 2D Array as soon as program runs 

	    cout << endl;
	    cout << "  FARNBOROUGH AIRPORT TEMPERATURE PROGRAM" << "\n";
		cout << "  ----------------------------------------" << "\n";
        cout << "                Main Menu                " << "\n";
		cout << "  ----------------------------------------" << "\n";
        cout << "  Please Select one of the Following Areas" << "\n";
        cout << "  of the Airport by Entering it's Number" << "\n";
		cout << "  in the Prompt Below and Pressing Enter." << "\n";
		cout << "  ----------------------------------------" << "\n\n";
        cout << "  1. The Terminal" << "\n";
        cout << "  2. Passenger Lounge" << "\n";
        cout << "  3. Crew Lounge" << "\n";
        cout << "  4. Service Area" << "\n";
		cout << "  5. Private Lounge" << "\n"; 
	    cout << "  6. Whole Airport" << "\n\n\n";
		
		cout << "  Choice.. "; 
        cin >> choice; 
		
		cout << "\n\n\n";

        switch (choice)
        {
		    case 1: 
				subMenu(choice-1); break;  
			case 2:
				subMenu(choice-1); break;
			case 3:
				subMenu(choice-1); break;
			case 4:
				subMenu(choice-1); break;
			case 5:
				subMenu(choice-1); break;
			case 6:
				wholeAirport(); break;
            default:
	            cout << "  Invalid Choice, Please Input a Number Between 1 and 6" << "\n\n\n\n\n"; system("pause");
		}
}