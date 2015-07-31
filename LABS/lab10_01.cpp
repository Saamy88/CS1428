/* Name: Samuel Cordova
 * Date: 11/06/13
 * Section: 06
 * LAB Number: 10
 *
 * This program will prompt the user for their hours they worked
 * and the program will calculated the amount of payment including
 * its extra hours if they had any.
 */

#include <iostream>

using namespace std;

const double PAY_RATE = 20.55;
const double BASE_HOURS = 30.0;
const double OT_MULTIPLIER = 1.5;

double basePay (float hours);
double overtimePay (float hours);

int main()
{

	float hours;

	double pay,
	       total_payment,
	       overtime;

	cout << "How many hours did you worked? ";
	cin >> hours;

	if (hours < 0 )
	{
		cout << endl << "Invalid number of hours. " << endl;

		return 1;
	}

	total_payment = overtimePay(hours) + basePay(hours);

	cout << "Your base pay is: " << basePay(hours) << endl
		 << "The overtime pay: " << overtimePay(hours) << endl
		 << "Your total pay is: " << total_payment << endl;

	return 0;
}

double basePay (float hours)
{
	if (hours < BASE_HOURS)
	{
		return (PAY_RATE * hours);
	}

	return (BASE_HOURS * PAY_RATE);
}

double overtimePay (float hours)
{
	double extra = 0.0;

	if(hours > BASE_HOURS)
	{
		extra = hours - BASE_HOURS;
		extra = extra * OT_MULTIPLIER * PAY_RATE;
	}

	return extra;

}



