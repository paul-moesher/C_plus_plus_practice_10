//---------------------------------------------------------------------------------------------------------------------------------------------------
// CS2010									Program 6								Due date:3/23/18
// Paul Moesher																		Class time: 10:30
// Purpose: The purpose of this program is to analyzing temptures for March, April, and May and use this data to
// determine if the earth is warming up. 
// Input: The input is coming from the txt document. The document has 92 temptures one for each day March - May.
// Processing: The program takes all of the 92 entries and uses them to show the average for each month and display how
// many of the 92 days were above the average.
// Output: The program will show the temptures in Celsius for the first month and in Fahrenheit for the second month.
//-----------------------------------------------------------------------------------------------------------------------------------------------------

// Note to self March = 31 days, April = 30, May = 31

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Function declarations

void read_file(double tempratures[]);

void display_temperatures(double temps[], string month, string units);

void convert_temps(double temps[]);

double avg_temps(double temps[]);

void above_avg(double temps[], double avgTemp);

void highest_temps(double temps[], string month);

int main()
{
	// Declare  array
	double tempratures[92];

	// Declare variables
	double avg_temp;

	// Call read_file function
	read_file(tempratures);

	// Call dispaly_tempertaures function
	display_temperatures(tempratures, "March", "Celsius");

	// Call the convert_temps function
	convert_temps(tempratures);

	// Call the display_temperatures function
	display_temperatures(tempratures, "April", "Fahrenheit");

	// Tell the main that avg_temp = avg_temps
	avg_temp=avg_temps(tempratures);

	// Display a message stating that the average tempertature for the past 3 months is about to be displayed
	cout << endl << "Average temperature for the 3 months: " << avg_temp << endl;

	// Call the above_avg function to the main
	above_avg(tempratures, avg_temp);

	// Call the highest temp for each month
	highest_temps(tempratures, "March");

	highest_temps(tempratures, "April");

	highest_temps(tempratures, "May");

	system("pause");
	return 0;
}

// Access the temperatures stored in the program 6 txt document and stores it in an array

void read_file(double temprature[])  // Note to self this is a differnt way then before to pull data from a text file

{

	ifstream inFile("pgm6.txt");

	if (!inFile)

	{
		cout << "Error cannot open file" << endl;
		system("pause");
		exit(1);
	}

	int i = 0;

	while (inFile >> temprature[i])

	{
		i++;
	}

	inFile.close();
}


//write the function that converts the Celsius value to Fahrenheit

void convert_temps(double temps[])

{

	int i = 0;

	while (i<92)

	{

		temps[i] = (9.0 / 5.0)*temps[i] + 32;

		i++;

	}

}

// Write a function that finds the number of days that the temperature was above the average temperature for that day


void above_avg(double temps[], double avgTemp)

{

	int i = 0;

	int avg_temp = 0;

	while (i<92)

	{

		if (temps[i]>avgTemp)

		{

			avg_temp++;

		}

		i++;

	}

	cout << endl << avg_temp << " days had a temperature above the average for this period " << endl;

}

// This function finds the average temperature of each month

double avg_temps(double temps[])

{

	int i = 0;

	double totalTemp = 0;

	while (i<90)

	{

		totalTemp = totalTemp + temps[i];

		i++;

	}

	return (totalTemp / i);

}

//Finds the average temprature of a month

double avgTemps(double temps[])

{

	int i = 0;

	double totalTemp = 0;

	while (i<90)

	{

		totalTemp = totalTemp + temps[i];

		i++;

	}

	return (totalTemp / i);

}

// function to display the temperatures

void display_temperatures(double temps[], string month, string units)
{

	if (month == "March")

	{
		cout << setw(10) << "Paul Moesher" << endl;

		cout << setw(10) << "CS2010, Spring 2018, 10:30" << endl;

		cout << "" << endl; // Line for space

		cout << "Temperatures for March" << endl;

		cout << setw(10) << "Day of month\t" << setw(10) << " Temperature (" << units << ")" << endl;

		cout << "---------------------------" << endl;

		int i = 0;

		while (i < 31)

		{
			cout << setw(5) << i + 1 << "\t" << setw(15) << temps[i] << endl;

			i++;
		}


	}

	else if (month == "April")

	{

		cout << "" << endl;

		cout << "Temperatures for April" << endl;


		cout << setw(10) << "Day of month\t" << setw(10) << "Temperature (" << units << ")" << endl;

		cout << "---------------------------" << endl << endl;

		int i = 31;

		while (i<61)

		{

			cout << setw(5) << i + 1 - 31 << "\t" << setw(15) << temps[i] << endl;

			i++;


		}


	}

	else if (month == "May")

	{

		cout << "Temperatures for May" << endl;

		cout << setw(10) << "Day\t" << setw(10) << "Temperature" << endl;

		cout << setw(10) << "of month\t" << "(" << units << ")" << endl;

		cout << "---------------------------" << endl << endl;

		int i = 61;

		while (i<92)

		{

			cout << setw(5) << i + 1 - 61 << "\t" << setw(15) << temps[i] << endl;

			i++;

		}

	}

}

// Write a function to find the highest temperature of a month

void highest_temps(double temps[], string month)

{

	double high = 0;

	if (month == "March")

	{

		cout << "Highest temperature for March: ";

		int i = 0;

		while (i<31)

		{

			if (temps[i]>high)

			{

				high = temps[i];

			}

			i++;



		}

		cout << high << endl;

	}

	else if (month == "April")

	{

		cout << "Highest temperature for April: ";

		int i = 31;

		while (i<61)

		{

			if (temps[i]>high)

			{

				high = temps[i];

			}

			i++;

		}

		cout << high << endl;

	}

	else if (month == "May")

	{

		cout << "Highest temperature for May: ";

		int i = 61;

		while (i<92)

		{

			if (temps[i]>high)

			{

				high = temps[i];

			}

			i++;

		}

		cout << high << endl;

	}

}