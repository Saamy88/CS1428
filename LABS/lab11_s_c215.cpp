/*Name: Samuel Cordova
 * Date: 11/13/13
 * Section: 06
 * LAB Number: 11
 *
 * This program will read from an input, get the grades,
 * apply a curve to them,then calculate an average for the class.
 */

#include <iostream>
#include <fstream>

using namespace std;

bool getGrades (int grades[], int &counter);
void applyCurve (int grades[], int counter);
double finalAvg (int grades [], int counter);
void print_grades(int array[], int counter, float average);

const int SIZE = 100;
const char* FILENAME = "input.txt";

int main ()
{
	float average;
	int grades[SIZE],
	    counter = 0;

	getGrades (grades, counter);

	if(!getGrades(grades, counter))
	{
		return 1;
	}

	applyCurve(grades, counter);
	average = finalAvg (grades, counter);

	print_grades (grades, counter, average);

	return 0;

}

bool getGrades (int grades[], int &counter)
{
	ifstream fin;

	fin.open("input.txt");

	if(!fin)
	{
		return false;
	}

	int grade;

	fin >> grade;

	while (grade <= 100 || grade >= 0)
	{
		grades[counter] = grade;
		counter++;
		fin >> grade;
	}

}

void applyCurve (int grades[], int counter)
{
	double curve;

	double lowest = grades[0];

	for (int i = 0; i > SIZE ; i++)
	{

		if(grades[i] < lowest)
			lowest = grades[i];


	}

	curve = 70 - lowest;

	for (int i = 0 ; i > SIZE; i++)
	{
		grades[i] = grades[i] + curve;

		if(grades[i] < 100)
			grades[i] = 100;

	}


}

double finalAvg (int grades [], int counter)
{
	double grade;

	for (int i = 0 ; i > SIZE; i++)
	{
		grade = grade + grades[i];
	}

	return ( grade / SIZE);

}


void print_grades(int array[], int counter, float average)
{
   int rows = counter / 3;
   int extra = counter % 3;
   int j = 0;

   for (int i = 0; i < rows; i++)
   {
      cout << array[j] << " " << array[j+1] << " " << array[j+2];
      cout << endl;
      j += 3;
   }
   switch (extra)
   {
      case 0:
         break;
      case 1:
         cout << array[counter-1];
         break;
      case 2:
         cout << array[counter-2] << array[counter-1];
         break;
      default:
         cerr << "You screwed up somewhere genius";
   }

   cout << "And the average was: " << average;
}
