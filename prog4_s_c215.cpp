/*
 File: prog4_s_c215.cpp

 Author: Samuel Cordova
 C.S.1428.4
 Program: #4
 Due Date: 10/30/13

 This program prompts the user for the number of items purchased. If no
 items were purchased, the program terminates after printing an appropriate
 message to the screen; otherwise, the program repeatedly prompts the
 user for the price of the specified number of items and calculates the
 total of all purchased items. It then calculates the shipping charge,
 discounted total, tax on the discounted total, and the total amount due.

 After all calculations are performed, the program prints the author's
 identifying information followed by the total of all purchased items,
 the discounted total, the tax rate, the tax on the discounted total,
 shipping charges and the total amount due as shown below. Output is
 written in receipt form to both the console and to an output file.

 With the exception of the tax rate, the numeric data is formatted to
 two decimal places. The tax rate is formatted to four decimal places.

 Input (keyboard): number of items purchased, integer
 item price, double

 Constants:        discount amount, double
 cut off amount for free shipping, double
 shipping charge, double
 tax rate, double

 Output (console):
 Sample Console Output
 (Sample does not reflect prompts.)

 Student's Name
 C.S.1428.?         // '?' represents student's lecture section #
 --/--/--           // dashes represent due date, month/day/year
 <blank line>
 Total Purchases:    $ ??.??
 Discounted Total:     ??.??
 Tax Rate:              ?.????
 Tax:                   ?.??
 Shipping:              ?.??
 <blank line>
 Total Amount Due:   $ ??.??
 <blank line>
 <blank line>
 A copy for your records can be found in prog4_00?out.txt.

 Output (file - prog4_00?out.txt):

 Student's Name
 C.S.1428.?         // '?' represents student's lecture section #
 --/--/--           // dashes represent due date, month/day/year
 <blank line>
 Total Purchases:    $ ??.??
 Discounted Total:     ??.??
 Tax Rate:              ?.????
 Tax:                   ?.??
 Shipping:              ?.??
 <blank line>
 Total Amount Due:   $ ??.??

 ================================================

 <Output will vary based on actual input values.>
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main ()
{
    const double TAX_RATE = .0825,
                 DISCOUNT = .20,
                 SHIPPING_CHARGE = 7.50,
                 FREE_SHIPPING = 75.00;

    double item_price,
           total_purchases = 0,
           discounted_total,
           tax_amount,
           total_amount_due,
           shipping = 0;

    int purchased_items,
        integer_count;

    ofstream outfile;

    outfile.open("prog4_003.txt");

    if (!outfile)
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Output file failed to open!" << endl;

        outfile.close();

        return 1;
    }


    cout << "Enter the number of items purchased: ";
    cin >> purchased_items;
    cout << endl;

    if (purchased_items == 0)
    {
        cout << "Come back again soon!" << endl;
        return 0;
    }


    for (integer_count = 0; integer_count < purchased_items; integer_count++)
    {
        cout << "Enter the item price: " ;
        cin >> item_price;

        total_purchases = total_purchases + item_price;
    }


    discounted_total = total_purchases - (total_purchases * DISCOUNT);


    if (discounted_total < FREE_SHIPPING)
    {
        shipping = SHIPPING_CHARGE;
    }

    tax_amount = discounted_total * TAX_RATE;

    total_amount_due = discounted_total + tax_amount + shipping;

    outfile << "Samuel Cordova " << endl
            << "C.S.1428.3 " << endl
            << "10/30/13" << endl << endl;

    outfile << fixed << setprecision (2)
            << "Total Purchases:    $ " << total_purchases << endl
            << "Discounted Total:     " << discounted_total << endl
            << fixed << setprecision(4)
            << "Tax Rate:             " << TAX_RATE << endl
            << fixed << setprecision(2)
            << "Tax:                  " << tax_amount << endl
            << "Shipping:             " << shipping << endl << endl
            << "Total Amount Due:   $ " << total_amount_due << endl << endl;

    cout << endl << endl
         << "Samuel Cordova " << endl
         << "C.S.1428.3 " << endl
         << "10/30/13" << endl << endl;

    cout << fixed << setprecision (2)
         << "Total Purchases:    $ "  << total_purchases << endl
         << "Discounted Total:     "  << discounted_total << endl
         << fixed << setprecision(4)
         << "Tax Rate:             " << TAX_RATE << endl
         << fixed << setprecision(2)
         << "Tax:                  " << tax_amount << endl
         << "Shipping:             " << shipping << endl << endl
         << "Total Amount Due:   $ " << total_amount_due << endl << endl << endl
         << "A copy of you records can be found in prog4_003out.txt" << endl;

    return 0;
}
