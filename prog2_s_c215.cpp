/*
   File: prog2_s_c215.cpp

   Author: Samuel Cordova
   C.S.1428.3
   Program: #2
   Due Date: 09/04/13

   This program prompts the user to enter the amount of a purchase (in cents).
   It then prompts the user to enter the amount received in payment (in cents).
   It calculates the amount of change due, printing the results to an output
   file. The author's identifying information is provided followed by the
   number of each coin to be given in change: the number of dollars, half
   dollars, quarters, dimes, nickels and pennies are listed in tabular form.
   Monetary amounts are displayed to two decimal places.

   An appropriate message is displayed to the console screen if the output
   file fails to open.

   An appropriate message is written to the console screen informing the
   user of the output file name to which the results have been written.
   The layout and content of the file output are shown in the sample below.

   Input (keyboard):
          purchase amount, integer (in cents)
          payment amount, integer (in cents)

   Constants: none

   Output (screen):

           Author's Name
           C.S.1428.?        // '?' represents author's lecture section #
           --/--/--          // dashes represent due date, month/day/year
           <blank line>
           <Appropriate message indicating the name of the output file.>

   Output (file - prog2_00?out.txt): // '?' represents author's lect sec #

           Author's Name
           C.S.1428.?        // '?' represents author's lecture section #
           --/--/--          // dashes represent due date, month/day/year
           <blank line>
           Received ? for a purchase of ?
           <blank line>
              Change in coins:
           Coin           Number
           ---------------------
           Dollars          ?
           Half Dollars     ?
           Quarters         ?
           Dimes            ?
           Nickels          ?
           Pennies          ?

   ================================================

   <Output will vary based on actual input values.>
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main ()
{
    ofstream output;
    output.open ("prog2_s_c215out.txt");

    if (!output)
    {
        cout << endl << endl
             << "Program Terminated " << endl << endl
             << "Output file failed " << endl;

        output.close ();

        return 1;
    }

    double purchase,
    	   payment;

    int bills,
        change_cents,
        half_dollars,
        quarters,
        nickels,
        dimes;

    cout << "Enter the amount of the purchase (in cents): ";
    cin >> purchase;
    cout << "Enter the amount received in payment (in cents): ";
    cin >> payment;

    change_cents = payment - purchase;
    bills = change_cents / 100;

    change_cents = change_cents % 100;
    half_dollars = change_cents / 50;

    change_cents = change_cents % 50;
    quarters = change_cents / 25;

    change_cents = change_cents % 25;
    dimes = change_cents / 10;

    change_cents = change_cents % 10;
    nickels = change_cents / 10 ;

    output << "Samuel Cordova " << endl
           << "C.S.1428.3 " << endl
           << "09/04/13" << endl << endl ;

    output << fixed << setprecision (2) << endl
           << "Received " << payment / 100 << " for a purchase of "
           << purchase / 100 << endl << endl
           << "  Change in coins: " << endl
           << "Coin          Number" << endl
           << "____________________" << endl
           << "Dollars     " << setw(6) << bills << endl
           << "Half_Dollars" << setw(6) << half_dollars << endl
           << "Quarters    " << setw(6) << quarters << endl
           << "Dimes       " << setw(6) << dimes << endl
           << "Nickels     " << setw(6) << nickels << endl
           << "Pennies     " << setw(6) << change_cents << endl<< endl;

    cout << endl << endl
         << "Samuel Cordova " << endl
         << "C.S.1428.3 " << endl
         << "09/04/13" << endl << endl
         << "Program result have been written to prog2_s_c215out.txt" << endl;

    output.close ();


    return 0;
}
