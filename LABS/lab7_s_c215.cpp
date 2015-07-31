/* Name: Samuel Cordova
 * Date: 10-16-13
 * Section 06
 * LAB Number: 7
 *
 * This program will ask for you grades and it will calculate your
 * average. You have the decision to continue the program or not.
 *
 */

#include <iostream>

using namespace std;

int main ()
{


	int sum_grades = 0,
			grades,
			number_grades = 0,
			decision;

	double average;

	do
	{

		cout << "Enter your grades or enter negative number to stop: ";
		cin >> grades;

	while ( grades >= 0 && grades <= 100  )
	{
	         sum_grades = sum_grades + grades;
	         cout<< "Enter your grades or enter negative number to stop: ";
	         cin >> grades;
	         number_grades++;

	 }

		average = sum_grades / number_grades;

		cout << endl
	         << "The average is " << average << "." << endl << endl
	         << "Do you want to continue?" << endl
	         << "Press '0' for yes. Press '1' for no. " << endl;
		 cin >> decision;


	} while (decision == 0);

	return 0;


}
