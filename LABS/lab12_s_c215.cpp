/*Name: Samuel Cordova
 * Date: 11/20/13
 * Section: 06
 * LAB Number 12
 *
 * This program uses an structure in a one dimensional array.
 * The program will read a list of names and averages and
 * display them in an output file with a grade after their average.
 *
*/
#include <iostream>
#include <fstream>

using namespace std;

struct studentRecord
{
	string First,
	       Last;

	double average;

	char grade;
};

bool getData ( studentRecord data[]);
void assignGrade ( studentRecord data[] );
bool printData ( studentRecord data[]);

const int SIZE = 15;

int main ( )
{


	studentRecord data[SIZE];

	if ( !getData(data) )
	{
		cout << endl << endl
		     << "Something went wrong with the input file!"
		     << endl << endl;

		return 1;
	}

	getData ( data );
	assignGrade ( data );
	printData ( data );

	return 0;

}

bool getData ( studentRecord data[])
{
	ifstream fin;

	fin.open ("input.txt");

	if (!fin )
		return false;

	for ( int i = 0; i < SIZE; i++  )
	{
		fin >> data[i].First >> data[i].Last >> data[i].average;
	}

	fin.close();

	return true;
}

void assignGrade ( studentRecord data[] )
{
	for ( int i = 0; i < SIZE; i++  )
	{
		if (data[i].average >= 89.5 )
		{
			data[i].grade = 'A';
	    }


		else if (data[i].average >= 79.5)
		{
			data[i].grade = 'B';
	    }

		else if (data[i].average >= 69.5)
	    {
			data[i].grade = 'C';
	    }

	    else if (data[i].average >= 59.5)
	    {
	    	data[i].grade = 'D';
	    }
	    else
	    {
	    	data[i].grade = 'F';
	    }
	}
}

bool printData ( studentRecord data[])
{
	ofstream fout;

	fout.open ("output.txt");

	if ( !fout )
		return false;

	for ( int i = 0; i < SIZE; i++  )
	{
		fout << data[i].First << " " << data[i].Last << " Average "
			 << data[i].average << " Grade: " << data[i].grade << endl;
	}

	return true;
}
