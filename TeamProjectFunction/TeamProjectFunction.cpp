// Teamproject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
void InputList(double num[]);
int Menu();
void SaveInOutput(double num[]);
void Display(double num[]);
double GetTotal(double num[]);
double GetAverage(double num[]);
double GetLargest(double num[]);
double GetSmallest(double num[]);
double GetNumOccurrences(double num[]);
double* ScaleUp(double num[]);
double* Reverse(double num[]);
double* ZeroBase(double num[]);
bool ReWrite(char lett);

int main()
{

	// Declaring variables
	double numbers[12], Average, Largest, Smallest, Total, occ;
	int option;
	char letter;

	// Input section
	 InputList(numbers);

	// Menu
	do {
		option=Menu();

		switch (option) {

			// Menu option 1: Display numbers
		case 1: Display(numbers);


			break;


			// Menu option 2: Totals 
		case 2:

			Total = GetTotal(numbers);

			cout << "Your total is " << Total << "." << endl << endl;


			break;

			// Menu option 3: Average
		case 3: cout << "You have chosen option 3. Here is your average" << endl << endl;


			Average = GetAverage(numbers);

			cout << "Your average is " << fixed << setprecision(2) << Average << "." << endl<<endl;

			break;

			// Menu option 4: Largest
		case 4: cout << "You have chosen option 4." << endl << endl;

			Largest = GetLargest(numbers);

			cout << "Your largest number is " << Largest << "." << endl << endl;

			break;

			// Menu option: Smallest number
		case 5: cout << "You have chosen option 5." << endl << endl;

			Smallest = GetSmallest(numbers);

			cout << "Your smallest number is " << Smallest << "." << endl << endl;

			break;

			// Menu option 6: Occurances
		case 6:
			occ = GetNumOccurrences(numbers);

			cout << " appears " << occ << " times." << endl<<endl;
			break;

			//Menu option 7: Scale
		case 7:

			ScaleUp(numbers);

			break;

			//Menu option 8: Reversed numbers
		case 8:

			Reverse(numbers);

			break;

			// Menu option 9: Lowest number
		case 9:
			ZeroBase(numbers);

			break;

			//Menu option 99: Choice to rewrite file with Y/N, or exit application
		case 99:
			SaveInOutput(numbers);
			cout << "You have chosen option 99. Your numbers are written in file Output.dat" << endl<<endl;
			cout << "Would you like to rewrite your numbers and continue" << endl<<endl;
			cout << "Enter Y(Yes)/N(No): ";
			cin >> letter;

			if (ReWrite(letter))
			{
				cout << endl;
				option=Menu();

			}
			else
			{
				cout << endl;
				cout << "Goodbye" << endl << endl;
			}
				break;

			// Invlaid output
		default: cout << "Invalid input." << endl << endl;
		}
		cout << "Press Enter to continue.." << endl;
		cin.get();
		cin.get();
		cout << "--------------------------------------------------------------------------------" << endl;
	} while (option!=99);

	return 0;
}
bool ReWrite(char lett)
{
	char Yes = 'Y';
	if (lett ==Yes)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void InputList(double num[])
{
	ifstream infile("input.dat");

	for (int row = 0; row < 3; row++)
	
	
	// Taking in 12 numbers and displaying numbers
	for (int i = 0; i < 12; i++) {
		infile >> num[i];
		
	}
	infile.close();
}

// Menu: Choices for the menu 1 to 99
int Menu()
{
	int chois;
	cout << "Input the number of the option you would like." << endl << endl
		<< "1:    Display numbers." << endl
		<< "2:    Total." << endl
		<< "3:    Average." << endl
		<< "4:    Largest." << endl
		<< "5:    Smallest." << endl
		<< "6:    Occurences of value." << endl
		<< "7:    Scale up." << endl
		<< "8:    Reverse." << endl
		<< "9:    Zero Base" << endl
		<< "99:   Exit." << endl;

	cin >> chois;
	return chois;
}

//Shows new numbers stored in "Output.dat" file
void SaveInOutput(double num[])
{
	ofstream outfile("Output.dat");
	
	outfile << "Here are your numbers: ";
	for (int i = 0; i < 12; i++) {
		
		outfile << num[i] << "  ";
	}
	
}

// Menu option 1: Displaying the numbers
void Display(double num[])
{
	cout << "You chose option 1. Here are your numbers" << endl << endl;
	for (int i = 0; i < 12; i++) {
		cout << num[i] << "  ";
	}
	cout << endl << endl;
}

//Menu option 2: total of the numbers
double GetTotal(double num[])
{
	cout << "You have chosen option 2. Here is the total" << endl << endl;
	double Tot = 0;

	for (int i = 0; i < 12; i++) {
		Tot += num[i];
	}
	return Tot;
}

//Menu option 3: Get average of numbers
double GetAverage(double num[])
{
	double Tot = 0;
	double Avg;

	for (int i = 0; i < 12; i++) {
		Tot += num[i];
	}

	Avg = Tot / 12;
	return Avg;
}

//Menu option 4: Getting largest number
double GetLargest(double num[])
{
	double Larg = num[0];

	for (int i = 0; i < 12; i++) {
		if (num[i] > Larg) {
			Larg = num[i];
		}
	}
	return Larg;
}

//Menu option 5: Getting the smallest number
double GetSmallest(double num[])
{
	double Small = num[0];

	for (int i = 0; i < 12; i++) {
		if (num[i] < Small) {
			Small = num[i];
		}
	}
	return Small;
}

//Menu option 6: The occurance of a certain value
double GetNumOccurrences(double num[])
{
	double numbers;
	cout << "You have chosen option 6." << endl << endl;

	cout << "Please enter which number you want: "<<endl;

	cin >> numbers;

	double occur = 0;

	for (int i = 0; i < 12; i++) {

		if (num[i] == numbers) {
			occur++;
		}
	}
	cout<<"The number " << numbers;
	return occur;
}

//Menu option 7: Scale up the numbers 
double* ScaleUp(double num[])
{
	double Scale = 0;
	cout << "You have chosen option 7." << endl << endl;

	cout << "How much would you like to scale by?" << endl;
	cin >> Scale;

	for (int i = 0; i < 12; i++) {
		num[i] = num[i] * Scale;
	}
	return num;
}

//Menu option 8: Reversing the numbers
double* Reverse(double num[])
{
	double temp = 0;
	cout << "You have chosen option 8. The numbers are now reversed." << endl << endl;

	for (int i = 0; i < 12 / 2; i++)
	{
		temp = num[i];
		num[i] = num[(12 - 1) - i];
		num[(12 - 1) - i] = temp;
	}
	return num;
}

//Menu option 9: The lowest number of all the numbers
double* ZeroBase(double num[])
{
	double min=num[0];
	cout << "You have chosen option 9. The lowest number is now zero." << endl << endl;

	for (int i = 0; i < 12; i++)
	{
		if (i == 1)
			min = num[0];

		if (num[i] < min)
		{
			min = num[i];
		}

	}
	for (int i = 0; i < 12; i++)
	{

		num[i] -= min;
	}
	return num;
}